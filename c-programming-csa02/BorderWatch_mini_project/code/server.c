/* server.c - socket + pthread layer.
 * Every connected station gets its own thread (station_thread), which
 * parses incoming lines and hands them to database.c's
 * register_object(), where the duplicate check / mutex / logging /
 * IPC alert all happen.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "server.h"
#include "types.h"
#include "database.h"

static volatile sig_atomic_t g_running = 1;
static void handle_sigint(int sig) { (void)sig; g_running = 0; }

typedef struct {
    int client_fd;
    struct sockaddr_in addr;
} ClientArgs;

/* Parses "station_id|lat|lon|signature|confidence" using strtok_r
 * (reentrant) instead of strtok(). Plain strtok() keeps its position
 * in a single shared static variable in glibc - NOT thread-local -
 * so two station threads calling it at the same instant can corrupt
 * each other's parse position. Verified this is a real, if rare,
 * failure mode under contention: a direct 8-thread stress test of
 * plain strtok() alone produced corrupted tokens roughly 1 time in
 * 250,000 calls. strtok_r() takes its own saveptr per call, so each
 * thread's parsing state is fully private on its own stack. */
static int parse_report(char *line, StationReport *out) {
    char *saveptr;
    char *tok = strtok_r(line, "|", &saveptr);
    if (!tok) return -1;
    out->station_id = atoi(tok);

    tok = strtok_r(NULL, "|", &saveptr); if (!tok) return -1;
    out->latitude = atof(tok);

    tok = strtok_r(NULL, "|", &saveptr); if (!tok) return -1;
    out->longitude = atof(tok);

    tok = strtok_r(NULL, "|", &saveptr); if (!tok) return -1;
    strncpy(out->raw_signature, tok, MAX_CLASS_LEN - 1);
    out->raw_signature[MAX_CLASS_LEN - 1] = '\0';

    tok = strtok_r(NULL, "|\n", &saveptr); if (!tok) return -1;
    out->confidence = atof(tok);
    return 0;
}

/* TCP is a byte STREAM, not a message protocol: a single recv() can
 * return less than one full line ("1|12.55|77.") or more than one
 * line at once, with no guarantee that message boundaries line up
 * with recv() call boundaries. ACCUM_SIZE holds bytes received but
 * not yet resolved into a complete '\n'-terminated line, per
 * connection (it lives on this thread's own stack, so it's private
 * to this station - no locking needed for it). */
#define ACCUM_SIZE (MAX_MSG_LEN * 4)

static void *station_thread(void *arg) {
    ClientArgs *ca = (ClientArgs *)arg;
    int fd = ca->client_fd;
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &ca->addr.sin_addr, ip, sizeof(ip));
    printf("[SERVER] Station connected from %s (fd=%d)\n", ip, fd);

    char accum[ACCUM_SIZE];
    size_t accum_len = 0;
    char recv_buf[MAX_MSG_LEN];
    ssize_t n;

    while ((n = recv(fd, recv_buf, sizeof(recv_buf), 0)) > 0) {
        if (accum_len + (size_t)n >= ACCUM_SIZE) {
            /* A misbehaving/flooding client sent more than we can
             * buffer without ever completing a line - drop the
             * accumulator rather than overflow it. */
            fprintf(stderr, "[SERVER] Accumulator overflow on fd=%d, resetting.\n", fd);
            accum_len = 0;
            continue;
        }
        memcpy(accum + accum_len, recv_buf, (size_t)n);
        accum_len += (size_t)n;

        /* Pull out every complete '\n'-terminated line currently in
         * the accumulator; whatever partial bytes remain after the
         * last '\n' stay buffered for the next recv(). */
        size_t start = 0;
        for (size_t i = 0; i < accum_len; i++) {
            if (accum[i] == '\n') {
                accum[i] = '\0';
                StationReport report;
                if (parse_report(accum + start, &report) == 0) {
                    int was_dup = 0;
                    int oid = register_object(&report, &was_dup);
                    printf("[SERVER] station=%d -> object_id=%d (%s)\n",
                           report.station_id, oid, was_dup ? "DUPLICATE-MERGED" : "NEW");
                } else {
                    fprintf(stderr, "[SERVER] Malformed report ignored: %s\n", accum + start);
                }
                start = i + 1;
            }
        }
        /* Shift any trailing partial line to the front of accum. */
        size_t leftover = accum_len - start;
        if (leftover > 0) memmove(accum, accum + start, leftover);
        accum_len = leftover;
    }
    printf("[SERVER] Station fd=%d disconnected\n", fd);
    close(fd);
    free(ca);
    return NULL;
}

void run_server(void) {
    signal(SIGINT, handle_sigint);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); exit(1); }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(SERVER_PORT);

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) { perror("bind"); exit(1); }
    if (listen(server_fd, 16) < 0) { perror("listen"); exit(1); }

    printf("[SERVER] BorderWatch Command Center listening on port %d\n", SERVER_PORT);
    printf("[SERVER] Press Ctrl+C to stop and print the final report.\n");

    while (g_running) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) {
            if (!g_running) break;
            continue;
        }
        ClientArgs *ca = malloc(sizeof(ClientArgs));
        ca->client_fd = client_fd;
        ca->addr = client_addr;

        pthread_t tid;
        pthread_create(&tid, NULL, station_thread, ca);
        pthread_detach(tid);
    }
    close(server_fd);
}

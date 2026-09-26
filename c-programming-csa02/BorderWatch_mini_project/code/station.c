/* station.c - simulates ONE monitoring station.
 * Build target `station` compiles ONLY this file (it has its own
 * main()), so it stays a separate executable from the command center.
 *
 * Usage: ./station <station_id>
 * Run two stations with overlapping coordinates within a few seconds
 * of each other to see database.c's duplicate merge kick in.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "types.h"
#include "station.h"

static void send_line(int fd, int station_id, double lat, double lon,
                       const char *sig, float conf) {
    char buf[MAX_MSG_LEN];
    int len = snprintf(buf, sizeof(buf), "%d|%.4f|%.4f|%s|%.2f\n",
                        station_id, lat, lon, sig, conf);
    send(fd, buf, len, 0);
    printf("[STATION %d] sent: %s", station_id, buf);
}

void run_station(int station_id) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) { perror("socket"); return; }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return;
    }
    printf("[STATION %d] connected to command center.\n", station_id);

    /* Demo sequence: this station and another one (run at the same
     * time with a different id) report almost the same coordinate
     * within TIME_WINDOW_SEC -> the server merges them into ONE
     * object instead of creating two. */
    send_line(fd, station_id, 12.55, 77.90, "HEAT_LARGE", 0.75);
    sleep(1);
    send_line(fd, station_id, 12.552, 77.902, "HEAT_LARGE", 0.90);
    sleep(2);
    send_line(fd, station_id, 13.20, 78.30, "METAL_LARGE", 0.65);
    sleep(1);
    send_line(fd, station_id, 10.40, 79.50, "SEISMIC", 0.55);

    sleep(1);
    close(fd);
    printf("[STATION %d] done, disconnected.\n", station_id);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <station_id>\n", argv[0]);
        return 1;
    }
    run_station(atoi(argv[1]));
    return 0;
}

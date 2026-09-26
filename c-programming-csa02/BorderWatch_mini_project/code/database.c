#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "database.h"
#include "object.h"
#include "duplicate.h"
#include "zones.h"
#include "logger.h"
#include "ipc.h"

static ObjectNode      *g_head    = NULL;   /* head of the dynamic linked list */
static int               g_next_id = 1;
static pthread_mutex_t   g_db_mutex = PTHREAD_MUTEX_INITIALIZER; /* protects g_head */
extern ZoneNode         *g_zone_root;       /* owned by server.c / main.c */

void db_init(void) { g_head = NULL; g_next_id = 1; }

void db_destroy(void) {
    pthread_mutex_lock(&g_db_mutex);
    ObjectNode *cur = g_head;
    while (cur) {
        ObjectNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    g_head = NULL;
    pthread_mutex_unlock(&g_db_mutex);
}

int register_object(const StationReport *report, int *was_duplicate) {
    time_t now = time(NULL);

    pthread_mutex_lock(&g_db_mutex);   /* ---- critical section start ---- */

    ObjectNode *match = find_duplicate(g_head, report, now);

    if (match) {
        merge_into_existing(match, report);
        int oid = match->object_id;
        char cls[MAX_CLASS_LEN];
        double lat = match->latitude, lon = match->longitude;
        float conf = match->confidence;
        strncpy(cls, match->classification, MAX_CLASS_LEN);

        pthread_mutex_unlock(&g_db_mutex); /* ---- critical section end ---- */

        log_event("DUPLICATE_MERGED", oid, report->station_id, cls, lat, lon, conf);
        if (was_duplicate) *was_duplicate = 1;
        return oid;
    }

    /* Genuinely new object: allocate, classify, place in zone tree. */
    ObjectNode *node = create_object(g_next_id, report);
    if (!node) {
        pthread_mutex_unlock(&g_db_mutex);
        if (was_duplicate) *was_duplicate = 0;
        return -1;
    }
    g_next_id++;
    node->zone_id = find_zone_recursive(g_zone_root, node->latitude, node->longitude);
    if (node->zone_id != -1) tag_object_in_zone(g_zone_root, node->zone_id);

    node->next = g_head;
    g_head = node;

    int oid = node->object_id;
    char cls[MAX_CLASS_LEN];
    strncpy(cls, node->classification, MAX_CLASS_LEN);
    double lat = node->latitude, lon = node->longitude;
    float conf = node->confidence;

    pthread_mutex_unlock(&g_db_mutex); /* ---- critical section end ---- */

    log_event("NEW_OBJECT", oid, report->station_id, cls, lat, lon, conf);
    if (is_high_priority(cls, conf)) {
        send_alert(oid, cls, lat, lon, conf);
    }

    if (was_duplicate) *was_duplicate = 0;
    return oid;
}

int db_count(void) {
    pthread_mutex_lock(&g_db_mutex);
    int c = 0;
    for (ObjectNode *n = g_head; n != NULL; n = n->next) c++;
    pthread_mutex_unlock(&g_db_mutex);
    return c;
}

void db_print_all(void) {
    pthread_mutex_lock(&g_db_mutex);
    printf("\n===== CENTRAL OBJECT DATABASE =====\n");
    for (ObjectNode *n = g_head; n != NULL; n = n->next) print_object(n);
    printf("====================================\n");
    pthread_mutex_unlock(&g_db_mutex);
}

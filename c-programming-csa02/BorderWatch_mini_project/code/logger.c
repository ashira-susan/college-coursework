#include <stdio.h>
#include <pthread.h>
#include "logger.h"
#include "types.h"

static pthread_mutex_t g_log_mutex = PTHREAD_MUTEX_INITIALIZER;

void logger_init(void) {
    FILE *f = fopen(LOG_FILE, "w"); /* fresh log each run */
    if (f) {
        fprintf(f, "==== BorderWatch Surveillance Log Started ====\n");
        fclose(f);
    }
}

void log_event(const char *event_type, int object_id, int station_id,
               const char *classification, double lat, double lon,
               float confidence) {
    pthread_mutex_lock(&g_log_mutex);
    FILE *f = fopen(LOG_FILE, "a");
    if (f) {
        time_t now = time(NULL);
        char timebuf[32];
        struct tm tm_info;
        localtime_r(&now, &tm_info);
        strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", &tm_info);
        fprintf(f, "[%s] %-16s obj_id=%-4d station=%-3d class=%-32s conf=%.2f loc=(%.4f,%.4f)\n",
                timebuf, event_type, object_id, station_id, classification,
                confidence, lat, lon);
        fclose(f);
    }
    pthread_mutex_unlock(&g_log_mutex);
}

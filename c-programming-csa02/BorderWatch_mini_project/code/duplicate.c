#include <math.h>
#include <string.h>
#include "duplicate.h"
#include "object.h"

double approx_distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat1 - lat2;
    double dlon = lon1 - lon2;
    return sqrt(dlat * dlat + dlon * dlon);
}

ObjectNode *find_duplicate(ObjectNode *head, const StationReport *report, time_t now) {
    for (ObjectNode *n = head; n != NULL; n = n->next) {
        double dt = difftime(now, n->last_seen);
        if (dt <= TIME_WINDOW_SEC) {
            double dist = approx_distance(report->latitude, report->longitude,
                                           n->latitude, n->longitude);
            if (dist <= DIST_THRESHOLD) {
                return n;   /* same object, seen by another station */
            }
        }
    }
    return NULL; /* nothing close enough in time+space -> it's new */
}

static void add_station_if_new(ObjectNode *n, int station_id) {
    for (int i = 0; i < n->num_stations; i++) {
        if (n->station_ids[i] == station_id) return; /* already recorded */
    }
    if (n->num_stations < MAX_STATIONS_PER_OBJ) {
        n->station_ids[n->num_stations++] = station_id;
    }
}

void merge_into_existing(ObjectNode *existing, const StationReport *report) {
    char classification[MAX_CLASS_LEN];
    classify_object(report->raw_signature, classification);

    existing->last_seen = time(NULL);
    existing->report_count++;

    if (report->confidence > existing->confidence) {
        existing->confidence = report->confidence;
        strncpy(existing->classification, classification, MAX_CLASS_LEN - 1);
        existing->classification[MAX_CLASS_LEN - 1] = '\0';
    }

    /* Nudge the stored location toward the average of every report -
     * a cheap way to converge on a single consistent position. */
    existing->latitude  = (existing->latitude  + report->latitude)  / 2.0;
    existing->longitude = (existing->longitude + report->longitude) / 2.0;

    add_station_if_new(existing, report->station_id);
}

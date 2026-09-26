#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "object.h"

void classify_object(const char *raw_signature, char *out_classification) {
    if (strcasecmp(raw_signature, "HEAT_LARGE") == 0) {
        strncpy(out_classification, "Person/Animal (Large Heat Sig)", MAX_CLASS_LEN - 1);
    } else if (strcasecmp(raw_signature, "HEAT_SMALL") == 0) {
        strncpy(out_classification, "Small Animal (Small Heat Sig)", MAX_CLASS_LEN - 1);
    } else if (strcasecmp(raw_signature, "METAL_LARGE") == 0) {
        strncpy(out_classification, "Vehicle (Large Metal Sig)", MAX_CLASS_LEN - 1);
    } else if (strcasecmp(raw_signature, "METAL_SMALL") == 0) {
        strncpy(out_classification, "Weapon/Equipment (Small Metal)", MAX_CLASS_LEN - 1);
    } else if (strcasecmp(raw_signature, "SEISMIC") == 0) {
        strncpy(out_classification, "Ground Movement (Seismic)", MAX_CLASS_LEN - 1);
    } else {
        strncpy(out_classification, "Unclassified", MAX_CLASS_LEN - 1);
    }
    out_classification[MAX_CLASS_LEN - 1] = '\0';
}

int is_high_priority(const char *classification, float confidence) {
    if (confidence < 0.6f) return 0;
    return (strstr(classification, "Person") != NULL ||
            strstr(classification, "Vehicle") != NULL ||
            strstr(classification, "Weapon") != NULL);
}

ObjectNode *create_object(int object_id, const StationReport *report) {
    ObjectNode *node = malloc(sizeof(ObjectNode)); /* dynamic memory allocation */
    if (!node) return NULL;

    node->object_id  = object_id;
    node->latitude   = report->latitude;
    node->longitude  = report->longitude;
    node->first_seen = time(NULL);
    node->last_seen  = node->first_seen;
    classify_object(report->raw_signature, node->classification);
    node->confidence    = report->confidence;
    node->report_count  = 1;
    node->num_stations  = 0;
    node->station_ids[node->num_stations++] = report->station_id;
    node->zone_id = -1;   /* database.c fills this in via the zone tree */
    node->next    = NULL;
    return node;
}

void print_object(const ObjectNode *node) {
    printf("ID %-3d | %-32s | conf %.2f | reports %-2d | stations %d | zone %d | (%.4f, %.4f)\n",
           node->object_id, node->classification, node->confidence,
           node->report_count, node->num_stations, node->zone_id,
           node->latitude, node->longitude);
}

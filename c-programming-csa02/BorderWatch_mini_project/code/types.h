#ifndef TYPES_H
#define TYPES_H

#include <time.h>

#define SERVER_PORT          9090
#define MAX_STATIONS_PER_OBJ 8
#define MAX_CLASS_LEN        32
#define MAX_MSG_LEN          256
#define LOG_FILE             "surveillance.log"

/* Two reports count as the SAME physical object if they arrive within
 * TIME_WINDOW_SEC of each other AND within DIST_THRESHOLD (degrees,
 * flat-earth approx - fine for one border sector). duplicate.c uses
 * these. */
#define TIME_WINDOW_SEC 5.0
#define DIST_THRESHOLD  0.01

/* What a station sends over the socket: "station_id|lat|lon|sig|conf\n" */
typedef struct {
    int    station_id;
    double latitude;
    double longitude;
    char   raw_signature[MAX_CLASS_LEN];
    float  confidence;
} StationReport;

/* One confirmed object in the central database. */
typedef struct ObjectNode {
    int    object_id;
    double latitude;
    double longitude;
    time_t first_seen;
    time_t last_seen;
    char   classification[MAX_CLASS_LEN];
    float  confidence;
    int    report_count;
    int    station_ids[MAX_STATIONS_PER_OBJ];
    int    num_stations;
    int    zone_id;
    struct ObjectNode *next;
} ObjectNode;

/* IPC alert payload (System V message queue). */
#define ALERT_MSG_TYPE 1
typedef struct {
    long   mtype;
    int    object_id;
    char   classification[MAX_CLASS_LEN];
    double latitude;
    double longitude;
    float  confidence;
} AlertMsg;

#define IPC_KEY_PATH "."
#define IPC_KEY_ID   'B'

#endif

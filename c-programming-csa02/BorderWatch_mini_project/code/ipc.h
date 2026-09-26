#ifndef IPC_H
#define IPC_H

/* Gets (creating if needed) the System V message queue that carries
 * alerts from the command center to the separate response.c process. */
int get_alert_queue(void);

void send_alert(int object_id, const char *classification,
                 double lat, double lon, float confidence);

#endif

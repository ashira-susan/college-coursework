#ifndef LOGGER_H
#define LOGGER_H

void logger_init(void);
void log_event(const char *event_type, int object_id, int station_id,
               const char *classification, double lat, double lon,
               float confidence);

#endif

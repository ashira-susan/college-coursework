#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

/* Dynamically allocates a brand-new ObjectNode from a station report,
 * classifies it, and fills in every field except zone_id/next
 * (the caller - database.c - fills those in once it knows the zone
 * and where in the list it goes). Returns NULL on malloc failure. */
ObjectNode *create_object(int object_id, const StationReport *report);

/* Raw sensor signature -> human classification string. */
void classify_object(const char *raw_signature, char *out_classification);

/* Is this classification+confidence worth an IPC alert? */
int is_high_priority(const char *classification, float confidence);

/* Pretty-print one object (used by database.c's dump). */
void print_object(const ObjectNode *node);

#endif

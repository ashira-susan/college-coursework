#ifndef DATABASE_H
#define DATABASE_H

#include "types.h"

void db_init(void);
void db_destroy(void);

/* The main entry point every station report goes through:
 *   1. lock mutex
 *   2. ask duplicate.c whether this matches an existing object
 *   3.   yes -> merge_into_existing()          (DUPLICATE path)
 *        no  -> object.c create_object()        (NEW path) + zone tag
 *   4. unlock mutex
 *   5. log the event to file, fire an IPC alert if high priority
 * Returns the object_id involved, sets *was_duplicate accordingly. */
int register_object(const StationReport *report, int *was_duplicate);

int  db_count(void);
void db_print_all(void);

#endif

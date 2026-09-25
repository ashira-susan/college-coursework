#ifndef SORT_H
#define SORT_H

#include "types.h"

typedef enum {
    SORT_BY_ID,
    SORT_BY_QUANTITY,
    SORT_BY_PRIORITY,
    SORT_BY_DEPARTMENT
} SortCriteria;

void sortByCriteria(Resource resources[], int count, SortCriteria criteria);
void sortMenu(Resource resources[], int count);

#endif

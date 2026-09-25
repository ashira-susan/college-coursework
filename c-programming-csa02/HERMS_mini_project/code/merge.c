#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "merge.h"
#include "resource.h"

/* Two resources are considered duplicates if they share the same ID,
   OR the same Name + Category. Department is deliberately excluded
   from the duplicate identity - otherwise records from different
   departments (the whole point of merging) could never match. */
static int isDuplicate(Resource a, Resource b) {
    if (a.id == b.id) return 1;
    if (strcasecmp(a.name, b.name) == 0 && strcasecmp(a.category, b.category) == 0) {
        return 1;
    }
    return 0;
}

/* Appends a department name to the consolidated record's department
   field, unless it is already present (checked with strstr), so
   repeated merges never produce "ICU, ICU". */
static void appendDepartmentIfNew(Resource *r, const char *newDept) {
    if (strstr(r->department, newDept) != NULL) {
        return;
    }
    if (strlen(r->department) == 0) {
        strncpy(r->department, newDept, DEPARTMENT_LEN - 1);
        r->department[DEPARTMENT_LEN - 1] = '\0';
    } else {
        strncat(r->department, ", ", DEPARTMENT_LEN - strlen(r->department) - 1);
        strncat(r->department, newDept, DEPARTMENT_LEN - strlen(r->department) - 1);
    }
}

void identifyDuplicates(Resource resources[], int count) {
    int found = 0;
    printf("\n--- Duplicate Resources ---\n");
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (isDuplicate(resources[i], resources[j])) {
                printf("Duplicate: [ID %d] %s (%s)  <-->  [ID %d] %s (%s)\n",
                       resources[i].id, resources[i].name, resources[i].department,
                       resources[j].id, resources[j].name, resources[j].department);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("No duplicate resources found.\n");
    }
}

/* Merges duplicates across the whole array. For every duplicate pair,
   quantities are summed into the first record, its department field
   absorbs the second record's department, status is recalculated,
   and the now-redundant second record is removed by shifting the
   remaining elements left. */
void mergeMenu(Resource resources[], int *count) {
    int mergedAny = 0;

    for (int i = 0; i < *count; i++) {
        for (int j = i + 1; j < *count; ) {
            if (isDuplicate(resources[i], resources[j])) {
                resources[i].quantity += resources[j].quantity;
                appendDepartmentIfNew(&resources[i], resources[j].department);
                calculateStatus(&resources[i]);

                for (int k = j; k < *count - 1; k++) {
                    resources[k] = resources[k + 1];
                }
                (*count)--;
                mergedAny = 1;
                /* don't increment j - a new record shifted into this slot */
            } else {
                j++;
            }
        }
    }

    if (mergedAny) {
        printf("Merge complete. Duplicate resources have been consolidated.\n");
    } else {
        printf("No duplicate resources found to merge.\n");
    }
}

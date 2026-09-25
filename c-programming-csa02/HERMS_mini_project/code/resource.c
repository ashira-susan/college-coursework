#include <stdio.h>
#include <string.h>
#include "resource.h"

/* Status is a derived field: it is never entered directly by the
   administrator, and is recalculated here whenever quantity or
   threshold changes (add, update, or merge). */
void calculateStatus(Resource *r) {
    if (r->quantity == 0) {
        strcpy(r->status, "CRITICAL");
    } else if (r->quantity < r->threshold) {
        strcpy(r->status, "LOW");
    } else {
        strcpy(r->status, "ADEQUATE");
    }
}

int findIndexByID(Resource resources[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (resources[i].id == id) {
            return i;
        }
    }
    return -1;
}

static void flushInputLine(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

void addResource(Resource resources[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Storage full. Cannot add more resources.\n");
        return;
    }

    Resource r;
    int id;

    printf("\n--- Add New Resource ---\n");

    while (1) {
        printf("Enter Resource ID: ");
        if (scanf("%d", &id) != 1) {
            printf("Invalid input. Please enter a number.\n");
            flushInputLine();
            continue;
        }
        flushInputLine();
        if (id <= 0) {
            printf("Resource ID must be positive.\n");
            continue;
        }
        if (findIndexByID(resources, *count, id) != -1) {
            printf("A resource with ID %d already exists. Use Update instead, or choose a different ID.\n", id);
            continue;
        }
        break;
    }
    r.id = id;

    printf("Enter Resource Name: ");
    readLine(r.name, NAME_LEN);

    printf("Enter Category (Medicine/Equipment/Bed/Supply): ");
    readLine(r.category, CATEGORY_LEN);

    printf("Enter Department: ");
    readLine(r.department, DEPARTMENT_LEN);

    while (1) {
        printf("Enter Quantity: ");
        if (scanf("%d", &r.quantity) != 1 || r.quantity < 0) {
            printf("Quantity must be a non-negative number.\n");
            flushInputLine();
            continue;
        }
        flushInputLine();
        break;
    }

    while (1) {
        printf("Enter Minimum Threshold: ");
        if (scanf("%d", &r.threshold) != 1 || r.threshold < 0) {
            printf("Threshold must be a non-negative number.\n");
            flushInputLine();
            continue;
        }
        flushInputLine();
        break;
    }

    printf("Enter Priority (High/Medium/Low): ");
    readLine(r.priority, PRIORITY_LEN);

    calculateStatus(&r);

    resources[*count] = r;
    (*count)++;

    printf("Resource added successfully. Status: %s\n", r.status);
}

void updateResource(Resource resources[], int count) {
    int id;
    printf("\n--- Update Resource ---\n");
    printf("Enter Resource ID to update: ");
    if (scanf("%d", &id) != 1) {
        flushInputLine();
        printf("Invalid input.\n");
        return;
    }
    flushInputLine();

    int index = findIndexByID(resources, count, id);
    if (index == -1) {
        printf("Resource with ID %d not found.\n", id);
        return;
    }

    /* Pointer to the actual record in the array, so the edits below
       modify the original resource rather than a copy. */
    Resource *ptr = &resources[index];

    printf("Editing: %s (current quantity: %d, threshold: %d)\n", ptr->name, ptr->quantity, ptr->threshold);

    printf("Enter new Quantity (-1 to keep unchanged): ");
    int q;
    if (scanf("%d", &q) == 1 && q >= 0) {
        ptr->quantity = q;
    }
    flushInputLine();

    printf("Enter new Threshold (-1 to keep unchanged): ");
    int t;
    if (scanf("%d", &t) == 1 && t >= 0) {
        ptr->threshold = t;
    }
    flushInputLine();

    printf("Enter new Priority (leave blank to keep unchanged): ");
    char buf[PRIORITY_LEN];
    readLine(buf, PRIORITY_LEN);
    if (strlen(buf) > 0) {
        strcpy(ptr->priority, buf);
    }

    calculateStatus(ptr);

    printf("Resource updated successfully. New status: %s\n", ptr->status);
}

void displayResourceRow(Resource r) {
    printf("%-5d %-20s %-12s %-8d %-10d %-8s %-10s %-.30s\n",
           r.id, r.name, r.category, r.quantity, r.threshold, r.priority, r.status, r.department);
}

void displayResources(Resource resources[], int count) {
    if (count == 0) {
        printf("\nNo resources to display.\n");
        return;
    }
    printf("\n%-5s %-20s %-12s %-8s %-10s %-8s %-10s %-s\n",
           "ID", "Name", "Category", "Qty", "Threshold", "Prior", "Status", "Department");
    printf("------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        displayResourceRow(resources[i]);
    }
}

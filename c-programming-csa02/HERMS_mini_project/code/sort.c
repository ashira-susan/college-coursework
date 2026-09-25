#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "sort.h"

static void swap(Resource *a, Resource *b) {
    Resource temp = *a;
    *a = *b;
    *b = temp;
}

/* Lower rank sorts first: High, then Medium, then Low. */
static int priorityRank(const char *priority) {
    if (strcasecmp(priority, "High") == 0) return 0;
    if (strcasecmp(priority, "Medium") == 0) return 1;
    if (strcasecmp(priority, "Low") == 0) return 2;
    return 3;
}

static int compare(Resource a, Resource b, SortCriteria criteria) {
    switch (criteria) {
        case SORT_BY_ID:
            return a.id - b.id;
        case SORT_BY_QUANTITY:
            return a.quantity - b.quantity;
        case SORT_BY_PRIORITY:
            return priorityRank(a.priority) - priorityRank(b.priority);
        case SORT_BY_DEPARTMENT:
            return strcmp(a.department, b.department);
        default:
            return 0;
    }
}

static int partition(Resource resources[], int low, int high, SortCriteria criteria) {
    Resource pivot = resources[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(resources[j], pivot, criteria) <= 0) {
            i++;
            swap(&resources[i], &resources[j]);
        }
    }
    swap(&resources[i + 1], &resources[high]);
    return i + 1;
}

/* Recursive Quick Sort. This is our required recursion demonstration:
   the array is partitioned around a pivot, then each side is sorted
   by a recursive call on that smaller sub-range. */
static void quickSort(Resource resources[], int low, int high, SortCriteria criteria) {
    if (low < high) {
        int pivotIndex = partition(resources, low, high, criteria);
        quickSort(resources, low, pivotIndex - 1, criteria);
        quickSort(resources, pivotIndex + 1, high, criteria);
    }
}

void sortByCriteria(Resource resources[], int count, SortCriteria criteria) {
    if (count <= 1) return;
    quickSort(resources, 0, count - 1, criteria);
}

void sortMenu(Resource resources[], int count) {
    if (count == 0) {
        printf("No resources to sort.\n");
        return;
    }

    int choice;
    printf("\n--- Sort Resources ---\n");
    printf("1. Sort by Quantity\n");
    printf("2. Sort by Priority\n");
    printf("3. Sort by Department\n");
    printf("4. Sort by ID\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) {
        int c; while ((c = getchar()) != '\n' && c != EOF);
        printf("Invalid choice.\n");
        return;
    }
    int c; while ((c = getchar()) != '\n' && c != EOF);

    switch (choice) {
        case 1: sortByCriteria(resources, count, SORT_BY_QUANTITY); break;
        case 2: sortByCriteria(resources, count, SORT_BY_PRIORITY); break;
        case 3: sortByCriteria(resources, count, SORT_BY_DEPARTMENT); break;
        case 4: sortByCriteria(resources, count, SORT_BY_ID); break;
        default:
            printf("Invalid choice.\n");
            return;
    }
    printf("Sorted successfully.\n");
}

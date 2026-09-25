#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "search.h"
#include "sort.h"
#include "resource.h"

static void toLower(char *dst, const char *src, int size) {
    int i = 0;
    for (; src[i] != '\0' && i < size - 1; i++) {
        dst[i] = (char)tolower((unsigned char)src[i]);
    }
    dst[i] = '\0';
}

static int containsIgnoreCase(const char *haystack, const char *needle) {
    char h[DEPARTMENT_LEN], n[DEPARTMENT_LEN];
    toLower(h, haystack, DEPARTMENT_LEN);
    toLower(n, needle, DEPARTMENT_LEN);
    return strstr(h, n) != NULL;
}

static void printResultHeader(void) {
    printf("\n%-5s %-20s %-12s %-8s %-10s %-8s %-10s %-s\n",
           "ID", "Name", "Category", "Qty", "Threshold", "Prior", "Status", "Department");
    printf("------------------------------------------------------------------------------------------\n");
}

static void flushInputLine(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void searchByIDMenu(Resource resources[], int count) {
    int id;
    printf("Enter Resource ID: ");
    if (scanf("%d", &id) != 1) { flushInputLine(); printf("Invalid input.\n"); return; }
    flushInputLine();

    int found = 0;
    printResultHeader();
    for (int i = 0; i < count; i++) {
        if (resources[i].id == id) {
            displayResourceRow(resources[i]);
            found = 1;
        }
    }
    if (!found) printf("No resource found with ID %d.\n", id);
}

static void searchByName(Resource resources[], int count) {
    char name[NAME_LEN];
    printf("Enter Resource Name (or part of it): ");
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';

    int found = 0;
    printResultHeader();
    for (int i = 0; i < count; i++) {
        if (containsIgnoreCase(resources[i].name, name)) {
            displayResourceRow(resources[i]);
            found = 1;
        }
    }
    if (!found) printf("No resource found matching name \"%s\".\n", name);
}

static void searchByCategory(Resource resources[], int count) {
    char category[CATEGORY_LEN];
    printf("Enter Category: ");
    fgets(category, CATEGORY_LEN, stdin);
    category[strcspn(category, "\n")] = '\0';

    int found = 0;
    printResultHeader();
    for (int i = 0; i < count; i++) {
        if (containsIgnoreCase(resources[i].category, category)) {
            displayResourceRow(resources[i]);
            found = 1;
        }
    }
    if (!found) printf("No resource found in category \"%s\".\n", category);
}

static void searchByDepartment(Resource resources[], int count) {
    char department[DEPARTMENT_LEN];
    printf("Enter Department: ");
    fgets(department, DEPARTMENT_LEN, stdin);
    department[strcspn(department, "\n")] = '\0';

    int found = 0;
    printResultHeader();
    for (int i = 0; i < count; i++) {
        if (containsIgnoreCase(resources[i].department, department)) {
            displayResourceRow(resources[i]);
            found = 1;
        }
    }
    if (!found) printf("No resource found in department \"%s\".\n", department);
}

/* Design decision: binary search requires ordered data. Rather than
   tracking a "currently sorted by" flag, we simply sort by ID first
   and then binary search - the user never has to worry about whether
   the array happens to be in the right order. */
static void binarySearchByID(Resource resources[], int count) {
    if (count == 0) {
        printf("No resources to search.\n");
        return;
    }

    sortByCriteria(resources, count, SORT_BY_ID);

    int id;
    printf("Enter Resource ID (binary search): ");
    if (scanf("%d", &id) != 1) { flushInputLine(); printf("Invalid input.\n"); return; }
    flushInputLine();

    int low = 0, high = count - 1;
    int result = -1;
    int comparisons = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;
        if (resources[mid].id == id) {
            result = mid;
            break;
        } else if (resources[mid].id < id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printResultHeader();
    if (result != -1) {
        displayResourceRow(resources[result]);
        printf("(Found in %d comparison(s) using binary search.)\n", comparisons);
    } else {
        printf("No resource found with ID %d. (%d comparisons)\n", id, comparisons);
    }
}

void searchMenu(Resource resources[], int count) {
    int choice;
    printf("\n--- Search Resource ---\n");
    printf("1. Search by ID (Linear)\n");
    printf("2. Search by Name\n");
    printf("3. Search by Category\n");
    printf("4. Search by Department\n");
    printf("5. Search by ID (Binary, auto-sorts by ID)\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) { flushInputLine(); printf("Invalid choice.\n"); return; }
    flushInputLine();

    switch (choice) {
        case 1: searchByIDMenu(resources, count); break;
        case 2: searchByName(resources, count); break;
        case 3: searchByCategory(resources, count); break;
        case 4: searchByDepartment(resources, count); break;
        case 5: binarySearchByID(resources, count); break;
        default: printf("Invalid choice.\n");
    }
}

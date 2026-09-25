#include <stdio.h>
#include <string.h>
#include "analysis.h"
#include "resource.h"

void analyseResources(Resource resources[], int count) {
    int adequate = 0, low = 0, critical = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(resources[i].status, "CRITICAL") == 0) critical++;
        else if (strcmp(resources[i].status, "LOW") == 0) low++;
        else adequate++;
    }

    printf("\n--- Resource Availability Analysis ---\n");
    printf("Total Resources     : %d\n", count);
    printf("Adequate Resources  : %d\n", adequate);
    printf("Low Stock Resources : %d\n", low);
    printf("Critical Resources  : %d\n", critical);
}

void displayCriticalLowStock(Resource resources[], int count) {
    int found = 0;

    printf("\n=== CRITICAL RESOURCES ===\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(resources[i].status, "CRITICAL") == 0) {
            displayResourceRow(resources[i]);
            found = 1;
        }
    }
    if (!found) printf("None.\n");

    found = 0;
    printf("\n=== LOW-STOCK RESOURCES ===\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(resources[i].status, "LOW") == 0) {
            displayResourceRow(resources[i]);
            found = 1;
        }
    }
    if (!found) printf("None.\n");
}

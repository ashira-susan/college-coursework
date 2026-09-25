#include <stdio.h>
#include "menu.h"
#include "resource.h"
#include "search.h"
#include "sort.h"
#include "merge.h"
#include "analysis.h"
#include "fileio.h"

static void displayMenu(void) {
    printf("\n========================================================\n");
    printf("       HOSPITAL EMERGENCY RESOURCE MANAGEMENT\n");
    printf("========================================================\n");
    printf(" 1. Add Resource\n");
    printf(" 2. Update Resource\n");
    printf(" 3. Display All Resources\n\n");
    printf(" 4. Search Resource\n");
    printf(" 5. Sort Resources\n\n");
    printf(" 6. Identify Duplicate Resources\n");
    printf(" 7. Merge Department Records\n\n");
    printf(" 8. Analyse Resource Availability\n");
    printf(" 9. Display Critical / Low-Stock Resources\n\n");
    printf("10. Generate Consolidated Report\n\n");
    printf("11. Save Records\n");
    printf("12. Load Records\n\n");
    printf(" 0. Exit\n");
    printf("========================================================\n");
    printf("Enter your choice: ");
}

void runMenu(Resource resources[], int *count) {
    int choice;

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        int c; while ((c = getchar()) != '\n' && c != EOF);

        switch (choice) {
            case 1: addResource(resources, count); break;
            case 2: updateResource(resources, *count); break;
            case 3: displayResources(resources, *count); break;
            case 4: searchMenu(resources, *count); break;
            case 5: sortMenu(resources, *count); break;
            case 6: identifyDuplicates(resources, *count); break;
            case 7: mergeMenu(resources, count); break;
            case 8: analyseResources(resources, *count); break;
            case 9: displayCriticalLowStock(resources, *count); break;
            case 10: generateReport(resources, *count); break;
            case 11: saveResources(resources, *count); break;
            case 12: loadResources(resources, count); break;
            case 0: printf("Exiting. Don't forget to save your records!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}

#include <stdio.h>
#include "types.h"
#include "menu.h"
#include "fileio.h"

int main(void) {
    Resource resources[MAX_RECORDS];
    int count = 0;
    char choice;

    printf("Hospital Emergency Resource Management System\n");
    printf("Load previously saved records? (y/n): ");
    if (scanf(" %c", &choice) != 1) {
        choice = 'n';
    }
    int c; while ((c = getchar()) != '\n' && c != EOF);

    if (choice == 'y' || choice == 'Y') {
        loadResources(resources, &count);
    }

    runMenu(resources, &count);

    return 0;
}

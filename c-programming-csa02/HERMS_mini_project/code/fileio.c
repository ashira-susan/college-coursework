#include <stdio.h>
#include <string.h>
#include "fileio.h"

/* Binary storage: the record count is written first, followed by the
   raw array of structures. This is efficient and preserves the data
   exactly as it exists in memory. */
void saveResources(Resource resources[], int count) {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (fp == NULL) {
        printf("Error: could not open %s for writing.\n", DATA_FILE);
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(resources, sizeof(Resource), count, fp);

    fclose(fp);
    printf("Saved %d record(s) to %s.\n", count, DATA_FILE);
}

int loadResources(Resource resources[], int *count) {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (fp == NULL) {
        printf("No existing data file found (%s). Starting fresh.\n", DATA_FILE);
        return 0;
    }

    int storedCount = 0;
    if (fread(&storedCount, sizeof(int), 1, fp) != 1) {
        printf("Data file appears empty or corrupted.\n");
        fclose(fp);
        return 0;
    }
    if (storedCount > MAX_RECORDS) storedCount = MAX_RECORDS;
    if (storedCount < 0) storedCount = 0;

    size_t readCount = fread(resources, sizeof(Resource), (size_t)storedCount, fp);
    *count = (int)readCount;

    fclose(fp);
    printf("Loaded %d record(s) from %s.\n", *count, DATA_FILE);
    return 1;
}

/* Human-readable report, kept separate from the binary data file so
   it can be opened directly and read by an administrator or evaluator. */
void generateReport(Resource resources[], int count) {
    FILE *fp = fopen(REPORT_FILE, "w");
    if (fp == NULL) {
        printf("Error: could not open %s for writing.\n", REPORT_FILE);
        return;
    }

    int adequate = 0, low = 0, critical = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(resources[i].status, "CRITICAL") == 0) critical++;
        else if (strcmp(resources[i].status, "LOW") == 0) low++;
        else adequate++;
    }

    fprintf(fp, "========================================================\n");
    fprintf(fp, "       HOSPITAL RESOURCE CONSOLIDATED REPORT\n");
    fprintf(fp, "========================================================\n\n");
    fprintf(fp, "Total Resources       : %d\n", count);
    fprintf(fp, "Adequate Resources    : %d\n", adequate);
    fprintf(fp, "Low Stock Resources   : %d\n", low);
    fprintf(fp, "Critical Resources    : %d\n\n", critical);

    fprintf(fp, "--------------------------------------------------------\n");
    fprintf(fp, "CRITICAL RESOURCES\n");
    fprintf(fp, "--------------------------------------------------------\n");
    fprintf(fp, "%-5s %-20s %-12s %-8s %-s\n", "ID", "Name", "Category", "Qty", "Department");
    for (int i = 0; i < count; i++) {
        if (strcmp(resources[i].status, "CRITICAL") == 0) {
            fprintf(fp, "%-5d %-20s %-12s %-8d %-s\n",
                    resources[i].id, resources[i].name, resources[i].category,
                    resources[i].quantity, resources[i].department);
        }
    }

    fprintf(fp, "\n--------------------------------------------------------\n");
    fprintf(fp, "LOW-STOCK RESOURCES\n");
    fprintf(fp, "--------------------------------------------------------\n");
    fprintf(fp, "%-5s %-20s %-12s %-8s %-s\n", "ID", "Name", "Category", "Qty", "Department");
    for (int i = 0; i < count; i++) {
        if (strcmp(resources[i].status, "LOW") == 0) {
            fprintf(fp, "%-5d %-20s %-12s %-8d %-s\n",
                    resources[i].id, resources[i].name, resources[i].category,
                    resources[i].quantity, resources[i].department);
        }
    }

    fprintf(fp, "\n--------------------------------------------------------\n");
    fprintf(fp, "ALL RESOURCES\n");
    fprintf(fp, "--------------------------------------------------------\n");
    fprintf(fp, "%-5s %-20s %-12s %-8s %-10s %-8s %-10s %-s\n",
            "ID", "Name", "Category", "Qty", "Threshold", "Prior", "Status", "Department");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%-5d %-20s %-12s %-8d %-10d %-8s %-10s %-s\n",
                resources[i].id, resources[i].name, resources[i].category,
                resources[i].quantity, resources[i].threshold,
                resources[i].priority, resources[i].status, resources[i].department);
    }

    fclose(fp);
    printf("Consolidated report written to %s.\n", REPORT_FILE);
}

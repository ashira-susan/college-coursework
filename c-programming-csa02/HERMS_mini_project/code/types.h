#ifndef TYPES_H
#define TYPES_H

#define MAX_RECORDS 100
#define NAME_LEN 50
#define CATEGORY_LEN 30
#define DEPARTMENT_LEN 60
#define PRIORITY_LEN 10
#define STATUS_LEN 15
#define DATA_FILE "resources.dat"
#define REPORT_FILE "consolidated_report.txt"

typedef struct {
    int id;
    char name[NAME_LEN];
    char category[CATEGORY_LEN];
    char department[DEPARTMENT_LEN];
    int quantity;
    int threshold;
    char priority[PRIORITY_LEN];
    char status[STATUS_LEN];
} Resource;

#endif

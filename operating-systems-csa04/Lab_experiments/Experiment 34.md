## 34. Sequential File Organization and Record Searching

### Problem Statement

Write a C program to create a sequential file containing records, store each record with a record number and data, and search for a particular record by reading the file sequentially.

### Program

```c id="r6n2wk"
#include <stdio.h>

struct Record
{
    int recordNumber;
    char data[256];
};

int main()
{
    FILE *file;
    struct Record record;
    int searchNumber;
    int found;

    /* Create file and write records */
    file = fopen("sequential_file.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return 1;
    }

    printf("Enter records (enter 0 to stop):\n");

    while (1)
    {
        printf("\nRecord Number: ");
        scanf("%d", &record.recordNumber);

        if (record.recordNumber == 0)
        {
            break;
        }

        printf("Data: ");
        scanf(" %255[^\n]", record.data);

        fprintf(file, "%d|%s\n",
                record.recordNumber,
                record.data);
    }

    fclose(file);

    /* Open file for reading */
    file = fopen("sequential_file.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return 1;
    }

    /* Search records */
    while (1)
    {
        printf("\nEnter record number to search (0 to exit): ");
        scanf("%d", &searchNumber);

        if (searchNumber == 0)
        {
            break;
        }

        rewind(file);
        found = 0;

        while (fscanf(file, "%d|%255[^\n]\n",
                      &record.recordNumber,
                      record.data)
```

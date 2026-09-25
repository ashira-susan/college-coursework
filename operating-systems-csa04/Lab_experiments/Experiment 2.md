# Experiment 2: File Copy Using File Handling

### Problem Statement

Write a C program to **copy the contents of one file into another file** using C file handling functions such as `fopen()`, `fgetc()`, `fputc()`, and `fclose()`.

### Program

```c id="q4m8vd"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char filename[100], c;

    printf("Enter the filename to open for reading:\n");
    scanf("%s", filename);

    fptr1 = fopen(filename, "r");

    if (fptr1 == NULL)
    {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }

    printf("Enter the filename to open for writing:\n");
    scanf("%s", filename);

    fptr2 = fopen(filename, "w");

    if (fptr2 == NULL)
    {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }

    c = fgetc(fptr1);

    while (c != EOF)
    {
        fputc(c, fptr
```

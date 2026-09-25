## 28. Search for a Pattern in a File Using `strstr()`

### Problem Statement

Write a C program to search for a given pattern in a text file and display all lines that contain the pattern.

### Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void searchFile(const char *pattern, const char *filename)
{
    FILE *file;
    char line[MAX_LINE_LENGTH];

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    printf("\nLines containing the pattern \"%s\":\n", pattern);

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strstr(lin
```

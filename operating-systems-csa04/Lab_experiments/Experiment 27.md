## 27. Search for a Pattern in a File

### Problem Statement

Write a C program to read a file line by line and compare each line with a given pattern. Display the lines that do not exactly match the entered pattern.

### Program

```c
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main()
{
    char fn[10], pat[10], temp[200];
    FILE *fp;

    printf("Enter file name: ");
    scanf("%s", fn);

    printf("Enter the pattern: ");
    scanf("%s", pat);

    fp = fopen(fn, "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while (!feof(fp))
    {
        fgets(temp, sizeof(temp), fp);

        if (strcmp(temp, pat))
        {
            printf
```

## 26. File Management Using C File Handling Functions

### Problem Statement

Write a C program to create and write data into a file, then reopen the file in read mode and display its contents using standard C file-handling functions.

### Program

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;

    // Open file for writing
    file = fopen("example.txt", "w");

    if (file == NULL)
    {
        printf("Error opening the file for writing.\n");
        return 1;
    }

    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a C file manag
```

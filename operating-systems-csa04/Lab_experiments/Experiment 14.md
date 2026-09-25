##  File Management Using System Calls

### Problem Statement

Write a C program to perform basic file management operations:

1. Create a file
2. Copy a file
3. Delete a file

The program should use appropriate **file handling functions and system calls**.

### C Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void copy()
{
    const char *sourcefile = "sasi.txt";
    const char *destination_file = "sk.txt";

    int source_fd = open(sourcefile, O_RDONLY);

    int dest_fd = open(destination_file,
                        O_WRONLY | O_CREAT | O_TRUNC,
```

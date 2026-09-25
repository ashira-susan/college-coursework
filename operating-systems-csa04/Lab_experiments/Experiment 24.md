## 24. File Operations Using System Calls

### Problem Statement

Write a C program to demonstrate basic file operations using **system calls**. The program should:

1. Create a file.
2. Open the file for writing.
3. Write data into the file.
4. Open the file for reading.
5. Read and display the data.
6. Close the file.
7. Delete the file.

### Program

```c id="k3x7qa"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd;
    char buffer[100];

    /* Create a new file */
    fd = creat("sample.txt", S_IRWXU);

    if (fd == -1)
    {
        perror("create");
        exit(1);
    }
    else
```

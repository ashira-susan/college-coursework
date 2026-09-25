## 25. File Error Handling Using `errno` and `perror()`

### Problem Statement

Write a C program to open a file using the `open()` system call and demonstrate how file-operation errors can be handled using the `errno` variable and the `perror()` function.

### Program

```c id="x6k2pm"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

extern int errno;

int main()
{
    int fd;

    fd = open("foo.txt", O_RDONLY | O_CREAT);

    printf("fd = %d\n", fd);

    if (fd == -1)
    {
        printf("Error Number = %d\n", errno);
        perror("Program");
    }

    return 0;
}
```

### Sample Output

If `foo.txt` is successful

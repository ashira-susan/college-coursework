## 40. File Permission Management

### Problem Statement

Write a C program to simulate **file permission management** using octal permission values. The program should accept a file permission value and display its corresponding read, write, and execute permission format for commonly used permissions.

### Program

```c id="n5x7kp"
#include <stdio.h>

int main()
{
    int permission;

    printf("Enter file permission in octal: ");
    scanf("%d", &permission);

    printf("\nFile permissions changed successfully.\n");
    printf("File: file.txt\n");
    printf("Permission: %d\n", permission);

    if (permission == 664)
    {
        printf("Permission format: rw-rw-r--\n");
    }
    else if
```

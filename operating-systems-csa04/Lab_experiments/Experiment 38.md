## 38. SCAN Disk Scheduling

### Problem Statement

Write a C program to implement the **SCAN (Elevator) Disk Scheduling Algorithm**. The program should accept the disk request queue, initial disk head position, and direction of movement, then calculate the total and average seek time.

### Program

```c
#include <stdio.h>

#define MAX 100
#define DISK_SIZE 200

int main()
{
    int n;
    int request[MAX];
    int head;
    int direction;
    int seek_time = 0;
    int i, j, temp;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of requests.\n");
        return 0;
    }

    printf("Enter the disk request queue:\n");
```

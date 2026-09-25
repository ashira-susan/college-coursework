## 37. FCFS Disk Scheduling

### Problem Statement

Write a C program to implement the **First-Come, First-Served (FCFS) Disk Scheduling Algorithm**. The program should accept a disk request queue and the initial position of the disk head, calculate the total seek time, and find the average seek time.

### Program

```c
#include <stdio.h>

#define MAX 100

int main()
{
    int n;
    int head;
    int request_queue[MAX];
    int seek_time = 0;
    int i;
    int distance;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of requests.\n");
        return 0;
    }

    printf("Enter the disk request queue:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &request_queue[i]);
    }

    printf("Enter the initial position of the disk head: ");
```

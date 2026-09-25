## 39. C-SCAN Disk Scheduling

### Problem Statement

Write a C program to implement the **C-SCAN (Circular SCAN) Disk Scheduling Algorithm**. The program should accept the disk request queue, initial disk head position, and direction of movement, then calculate the total and average seek time.

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
    int seek_time = 0;
    int i, j, temp;
    int direction;

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
        scanf("%d", &request[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("Enter direction (1 for right, 0 for left): ");
    scanf("%d", &direction);

    /* Sort the request queue */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp
```

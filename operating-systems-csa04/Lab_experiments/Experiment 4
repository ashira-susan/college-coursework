## CPU Scheduling Using First Come First Served (FCFS)

### Problem Statement

Design a CPU scheduling program in C using the **First Come First Served (FCFS)** technique with the following considerations:

* **a.** All processes are activated at time 0.
* **b.** Assume that no process waits on I/O devices.

### C Program

```c
#include <stdio.h>

int main()
{
    int n, i, bt[10], wt[10], tat[10];
    float awt, atat;
    int swt = 0, stat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (i = 0; i <
```

## 7. Non-Preemptive Shortest Job First (SJF) Scheduling with Arrival Time - Non-preemptive

### Problem Statement

Construct a scheduling program in C that selects the **available process with the shortest execution time** to execute next, considering the **arrival time** of each process.

### C Program

```c
#include <stdio.h>

int main()
{
    int at[10], bt[10], pr[10];
    int n, i, j, temp;
    int time = 0, count, over = 0;
    int sum_wait = 0, sum_turnaround = 0, start;
    float avgwait, avgturn;

    printf("Enter the number of processes\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time and execution time for process %d\n", i + 1);
        scanf("%d%d", &at[i], &bt[i]);

        pr[i] = i + 1;
    }

    /* Sort according to arrival time */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
            }
        }
    }

    printf("\n\nProcess\t|Arrival Time\t|Execution Time\t|Start Time\t|End Time\t|Waiting Time\t|Turnaround Time\n\n");

    while (over < n)
    {
        count = 0;

        for (i = over; i < n; i++)
        {
            if (at[i]()
```

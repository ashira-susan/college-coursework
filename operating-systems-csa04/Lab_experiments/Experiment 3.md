## 4. CPU Scheduling Using Shortest Job First (SJF)

### Problem Statement

Construct a scheduling program in C that selects the **waiting process with the smallest execution time** to execute next.

### C Program

```c
#include <stdio.h>

int main()
{
    int bt[10], p[10], wt[10], tat[10];
    int n, i, j, temp, total = 0;
    float awt, atat;

    printf("Enter number of process: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    /* SJF Sorting */
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }

    wt[0] = 0;

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt
```

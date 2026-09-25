## 6. CPU Scheduling Using Round Robin (RR)

### Problem Statement

Construct a scheduling program in C using the **Round Robin scheduling technique** with a given time quantum.

### C Program

```c
#include <stdio.h>

int main()
{
    int i, NOP, sum = 0, count = 0, y, quant;
    int wt = 0, tat = 0;
    int at[10], bt[10], temp[10];

    float avg_wt, avg_tat;

    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);

    y = NOP;

    for (i = 0; i < NOP; i++)
    {
        printf("\nEnter the Arrival and Burst Time of Process[%d]\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        temp[i] = bt[i];
    }

    printf("\nEnter the Time Quantum: ");
    scanf("%d", &quant);

    printf("\nProcess No\tBurst Time\tTurnaround Time\tWaiting Time\n");

    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum += temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
```

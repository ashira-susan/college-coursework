## 5. CPU Scheduling Using Priority Scheduling

### Problem Statement

Construct a scheduling program in C that selects the **waiting process with the highest priority** to execute next.

> **Note:** In this program, a **higher numerical value means higher priority**.

### C Program

```c
#include <stdio.h>

struct P
{
    char name;
    int bt, wt, tat, pr;
};

int main()
{
    int n, i, j, total = 0;
    float awt, atat;
    struct P p[10];

    printf("Enter the total number of Processes: ");
    scanf("%d", &n);

    printf("\nPlease Enter the Burst Time and Priority of each process:\n");

    for (i = 0; i < n; i++)
    {
        p[i].name = 'A' + i;

        printf("\nEnter the details of process %c\n", p[i].name);

        printf("Enter the burst time: ");
        scanf("%d", &p[i].bt);

        printf("Enter the priority: ");
        scanf("%d", &p[i].pr);
    }

    /* Priority Sorting */
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (p[i].pr < p[j].pr)
            {
                struct P t = p[i];
                p[i] = p[j];
                p[j] = t;
            }

    p[0].wt = 0;

    for (i = 1; i < n; i++)
        p[i].wt = p[i - 1].wt + p[i - 1].bt;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;
        total += p[i].wt;

        printf("%c\t%d\t\t%d\t\t%d\n",
               p[i].name, p[i].bt, p[i].wt, p[i].tat);
    }

    awt = (float)total / n;

    total = 0;

    for (i = 0; i < n; i++)
        total += p[i].tat;

    atat = (float)total / n;

    printf("\nAverage Waiting Time : %f", awt);
    printf("\nAverage Turnaround Time : %f\n", atat);

    return 0;
}
```

### Sample Input

```text
Enter the total number of Processes: 4

Please Enter the Burst Time and Priority of each process:

Enter the details of process A
Enter the burst time: 6
Enter the priority: 2

Enter the details of process B
Enter the burst time: 4
Enter the priority: 4

Enter the details of process C
Enter the burst time: 3
Enter the priority: 1

Enter the details of process D
Enter the burst time: 5
Enter the priority: 3
```

### Sample Output

```text
Process    Burst Time    Waiting Time    Turnaround Time

B          4             0               4
D          5             4               9
A          6             9               15
C          3             15              18

Average Waiting Time : 7.000000
Average Turnaround Time : 11.500000
```

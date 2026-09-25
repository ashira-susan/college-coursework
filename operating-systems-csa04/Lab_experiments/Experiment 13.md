##  Memory Allocation Using First Fit, Best Fit and Worst Fit

### Problem Statement

Write a C program to implement the following **memory allocation techniques**:

1. First Fit
2. Best Fit
3. Worst Fit

The program should allocate processes to available memory partitions based on the selected allocation technique.

### C Program

```c id="7w4p3k"
#include <stdio.h>

void bestfit(int mp[], int p[], int m, int n)
{
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (mp[i] > p[j])
        {
            printf("\n%d fits in %d", p[j], mp[i]);

            mp[i] = mp[i] - p[j++];
            i = i - 1;
        }
    }

    for (int i = j; i < m; i++)
    {
        printf("\n%d must wait for its process", p[i]);
    }
}

void rsort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
```

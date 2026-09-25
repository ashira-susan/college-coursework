## 33. Optimal Page Replacement Algorithm

### Problem Statement

Write a C program to implement the **Optimal Page Replacement Algorithm**. Given a reference string and a fixed number of memory frames, determine the page replacements and calculate the total number of page faults.

### Program

```c id="m8r4tk"
#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3

void printFrames(int frames[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }

    printf("\n");
```

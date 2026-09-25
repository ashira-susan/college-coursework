## 35. Indexed File Organization

### Problem Statement

Write a C program to implement **indexed file organization**. Store block numbers and their corresponding data, create an index table that maps each block number to its position, and use the index to search for a particular block.

### Program

```c id="n7k3pd"
#include <stdio.h>

#define MAX 10

int main()
{
    int blockNumber[MAX];
    int index[MAX];
    char data[MAX][50];

    int n, i, search, position;

    /* Initialize index */
    for (i = 0; i < MAX; i++)
    {
        index[i] = -1;
    }

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    /* Enter blocks */
```

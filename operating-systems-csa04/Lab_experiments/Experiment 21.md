## 21. Contiguous Memory Allocation and Deallocation

### Problem Statement

Write a C program to simulate **contiguous memory allocation**. The program should:

1. Initialize the memory as free.
2. Display the available memory blocks.
3. Allocate memory to processes.
4. Deallocate memory when a process finishes.
5. Display the memory status after each operation.

A process can be allocated memory only when a sufficiently large **contiguous free block** is available.

### Program

```c id="n5k2rd"
#include <stdio.h>

#define MAX_MEMORY 1000

int memory[MAX_MEMORY];

/* Function to initialize memory */
void initializeMemory()
{
    for (int i = 0; i < MAX_MEMORY; i++)
    {
        memory[i] = -1;
    }
}

/* Function to display memory status */
void displayMemory()
{
    int i, j;
    int count = 0;

    printf("Memory Status:\n");

    for (i = 0; i < MAX_MEMORY; i++)
    {
        if (memory[i] == -1)
        {
            count++;
            j = i;

            while (j < MAX_MEMORY && memory[j] == -1)
            {
                j++;
            }

            printf("Free memory block %d-%d\n", i, j - 1);

            i = j - 1;
        }
    }

    if (count == 0)
    {
        printf("No free memory available.\n");
    }
}

/* Function to allocate memory */
void allocateMemory(int processId, int size)
{
    int start = -1;
    int blockSize = 0;

    for (int i = 0; i < MAX_MEMORY; i++)
    {
        if (memory[i] == -1)
        {
            if (blockSize == 0)
            {
                start = i;
            }

            blockSize++;
        }
        else
        {
            blockSize = 0;
        }

        if (blockSize >= size)
        {
            break;
        }
    }

    if (blockSize >= size)
    {
        for (int i = start; i < start + size; i++)
        {
            memory[i] = processId;
        }

        printf("Allocated memor
```

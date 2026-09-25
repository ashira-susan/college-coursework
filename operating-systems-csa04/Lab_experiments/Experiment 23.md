## 23. First-Fit Memory Allocation

### Problem Statement

Write a C program to implement the **First-Fit Memory Allocation Algorithm**.

The program should:

1. Initialize the memory as free.
2. Display the available memory blocks.
3. Allocate memory to processes using the **First-Fit** strategy.
4. Deallocate memory when a process finishes.
5. Display the memory status after each operation.

In First-Fit allocation, the process is placed into the **first available memory block that is large enough** to satisfy its requirement.

### Program

```c id="f7n2km"
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
        if
```

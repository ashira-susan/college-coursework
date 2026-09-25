## 22. Best-Fit Memory Allocation

### Problem Statement

Write a C program to implement the **Best-Fit Memory Allocation Algorithm**.

The program should:

1. Initialize the memory as free.
2. Display the available memory blocks.
3. Allocate memory to processes using the **Best-Fit** strategy.
4. Deallocate memory when a process finishes.
5. Display the memory status after each operation.

In Best-Fit allocation, the process is placed into the **smallest available memory block that is large enough** to satisfy its requirement.

### Program

```c id="q8m3vx"
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

/* Function to allocate memory using Best-Fit algorithm */
void allocateMemory(int processId, int size)
{
    int start = -1;
    int blockSize = 0;
    int bestStart = -1;
    int bestSize = MAX_MEMORY + 1;

    for (int i = 0; i <= MAX_MEMORY; i++)
    {
        if (i < MAX_MEMORY && memory[i] == -1)
        {
            if (blockSize == 0)
            {
                start = i;
            }

            blockSize++;
        }
        else
        {
            if (blockSize >= size && blockSize < bestSize)
            {
                bestSize = blockSize;
                bestStart = start;
            }

            blockSize = 0;
        }
    }

    if (bestStart != -1)
    {
        for (int i = bestStart; i < bestStart + size; i++)
        {
            memory[i] = processId;
        }

        printf("Allocated memory block %d-%d to Process %d\n",
               bestStart,
               bestStart + size - 1,
               processId);
    }
    else
    {
        printf("Memory allocation for Process %d failed "
               "(not enough contiguous memory).\n",
               processId);
    }
}

/* Function to deallocate memory */
void deallocateMemory(int processId)
{
    for (int i = 0; i < MAX_MEMORY; i++)
    {
        if (memory[i] == processId)
        {
            memory[i] = -1;
        }
    }

    printf("Memory released by Process %d\n", processId);
}

int main()
{
    initializeMemory();

    displayMemory();

    allocateMemory(1, 200);
    displayMemory();

    allocateMemory(2, 300);
    displayMemory();

    deallocateMemory(1);
    displayMemory();

    allocateMemory(3, 400);
    displayMemory();

    return 0;
}
```

### Sample Output

```text id="a2x6kp"
Memory Status:
Free memory block 0-999

Allocated memory block 0-199 to Process 1
Memory Status:
Free memory block 200-999

Allocated memory block 200-499 to Process 2
Memory Status:
Free memory block 500-999

Memory released by Process 1
Memory Status:
Free memory block 0-199
Free memory block 500-999

Allocated memory block 500-899 to Process 3
Memory Status:
Free memory block 0-199
Free memory block 900-999
```

### Key Concepts

* **Best-Fit** → Allocates a process to the smallest free block that can accommodate it.
* `memory[]` → Represents the available memory.
* `-1` → Represents a free memory location.
* `bestStart` → Starting position of the best-fit block.
* `bestSize` → Size of the smallest suitable free block found.
* `allocateMemory()` → Searches all free blocks and selects the best fit.
* `deallocateMemory()` → Releases memory occupied by a process.
* `displayMemory()` → Shows the current free memory blocks.

### Best-Fit Logic

Suppose the available blocks are:

```text id="7qk2dc"
Block 1 → 100 units
Block 2 → 500 units
Block 3 → 300 units
Block 4 → 700 units
```

If a process requires **280 units**:

```text id="9z5m1a"
100  → Too small
500  → Suitable
300  → Suitable ← BEST FIT
700  → Suitable
```

So the process is allocated to the **300-unit block**, because it is the smallest block that can satisfy the request.

### Best-Fit Rule

```text id="h6n4yw"
Choose the smallest free block
that is large enough for the process.
```

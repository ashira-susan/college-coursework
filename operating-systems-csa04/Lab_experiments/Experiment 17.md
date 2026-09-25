## 17. Banker's Algorithm for Resource Allocation

### Problem Statement

Write a C program to implement the **Banker's Algorithm** for resource allocation. The program should accept a resource request from a process and determine whether the request can be granted while keeping the system in a **safe state**.

### Program

```c
#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int is_safe();

int available[MAX_RESOURCES] = {3, 3, 2};

/* Maximum resource requirement */
int maximum[MAX_PROCESSES][MAX_RESOURCES] =
{
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};

/* Currently allocated resources */
int allocation[MAX_PROCESSES][MAX_RESOURCES] =
{
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};

int request_resources(int process_num, int request[])
{
    /* Check if request can be granted */
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        if (request[i] > available[i] ||
            request[i] > maximum[process_num][i] - allocation[process_num][i])
        {
            return 0;
        }
    }

    /* Allocate resources temporarily */
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        available[i] -= request[i];
        allocation[process_num][i] += request[i];
        maximum[process_num][i] -= request[i];
    }

    /* Check for safe state */
    if (is_safe())
    {
        return 1;
    }
    else
    {
        /* Roll back allocation */
        for (int i = 0; i < MAX_RESOURCES; i++)
        {
            available[i] += request[i];
            allocation[process_num][i] -= request[i];
            maximum[process_num][i] += request[i];
        }

        return 0;
    }
}

int is_safe()
{
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};

    /* Initialize work array */
    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        work[i] = available[i];
    }

    int count = 0;

    while (count < MAX_PROCESSES)
    {
        int found = 0;

        for (int i = 0; i < MAX_PROCESSES; i++)
        {
            if (finish[i] == 0)
            {
                int j;

                for (j = 0; j < MAX_RESOURCES; j++)
                {
                    if (maximum[i][j] - allocation[i][j] > work[j])
                    {
                        break;
                    }
                }

                if (j == MAX_RESOURCES)
                {
                    for (int k = 0; k < MAX_RESOURCES; k++)
                    {
                        work[k] += allocation[i][k];
                    }

                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }

        if (found == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int process_num;
    int request[MAX_RESOURCES];

    printf("Enter process number (0 to 4): ");
    scanf("%d", &process_num);

    printf("Enter resource request (e.g., 0 1 0): ");

    for (int i = 0; i < MAX_RESOURCES; i++)
    {
        scanf("%d", &request[i]);
    }

    if (request_resources(process_num, request))
    {
        printf("Request granted.\n");
    }
    else
    {
        printf("Request denied. System is not in safe state.\n");
    }

    return 0;
}
```

### Sample Input / Output

#### Example 1 — Request Granted

```text
Enter process number (0 to 4): 1
Enter resource request (e.g., 0 1 0): 1 0 2
Request granted.
```

#### Example 2 — Request Denied

```text
Enter process number (0 to 4): 0
Enter resource request (e.g., 0 1 0): 3 3 3
Request denied. System is not in safe state.
```

### Key Concepts

* **Banker's Algorithm** → Deadlock-avoidance algorithm.
* `available[]` → Resources currently available.
* `maximum[][]` → Maximum resources each process may need.
* `allocation[][]` → Resources currently allocated to each process.
* **Need** → `Maximum - Allocation`.
* `request_resources()` → Checks and temporarily allocates a resource request.
* `is_safe()` → Checks whether the resulting state is safe.
* **Rollback** → If the request makes the system unsafe, the temporary allocation is undone.

### Important Formula

```text
Need[i][j] = Maximum[i][j] - Allocation[i][j]
```

A request can be considered only if:

```text
Request ≤ Available
```

and

```text
Request ≤ Need
```

After temporary allocation, the system must still be in a **safe state**.

### Important Note

The process numbers in this program are **0 to 4**, because the arrays use C's zero-based indexing:

```text
P0, P1, P2, P3, P4
```

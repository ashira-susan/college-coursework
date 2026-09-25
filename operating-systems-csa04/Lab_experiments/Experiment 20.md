## 20. Readers-Writers Problem Using Semaphores

### Problem Statement

Write a C program to implement the **Readers-Writers Problem** using threads and semaphores.

Multiple readers should be allowed to read shared data simultaneously, but a writer must have exclusive access to the shared data. The program should create reader and writer threads and perform multiple read and write operations.

### Program

```c id="r8f2md"
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, writeBlock;

int data = 0;
int readersCount = 0;

void* reader(void* arg)
{
    int i = 0;

    while (i < 10)
    {
        sem_wait(&mutex);

        readersCount++;

        if (readersCount == 1)
        {
            sem_wait(&writeBlock);
        }

        sem_post(&mutex);

        /* Reading operation */
        printf("Reader reads data: %d\n", data);

        sem_wait(&mutex);

        readersCount--;

        if (readersCount == 0)
        {
            sem_post(&writeBlock);
        }

        sem_post(&mutex);

        i++;
    }

    return NULL;
}

void* writer(void* arg)
{
    int
```

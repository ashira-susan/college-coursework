## 18. Producer-Consumer Problem Using Semaphores

### Problem Statement

Write a C program to implement the **Producer-Consumer Problem** using threads and semaphores. The producer should add items to a fixed-size buffer, while the consumer removes items from the buffer.

The program should produce and consume a maximum of 10 items.

### Program

```c id="8k3vqa"
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <Windows.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 10

int buffer[BUFFER_SIZE];

sem_t empty, full;

int produced_items = 0;
int consumed_items = 0;

void* producer(void* arg)
{
    while (produced_items < MAX_ITEMS)
    {
        sem_wait(&empty);

        /* Critical section: Add item to buffer */
        for (int i = 0; i < BUFFER_SIZE; i++)
        {
            if (buffer[i] == 0)
            {
                buffer[i] = produced_items + 1;

                printf("Produced: %d\n", buffer[i]);

                produced_items_
```

## 10. Dining Philosophers Problem Using Pthreads

### Problem Statement

Write a C program to solve the **Dining Philosophers Problem** using POSIX threads and mutex locks. Each philosopher alternates between thinking and eating and must acquire two chopsticks before eating.

### C Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];

void* philosopherLifeCycle(void* arg)
{
    int id = *((int*)arg);

    int left_chopstick = id;
    int right_chopstick = (id + 1) % NUM_PHILOSOPHERS;

    while (1)
    {
        // Think
        printf("Philosopher %d is thinking...\n", id);

        // Pick up chopsticks
        pthread_mutex_lock(&chopsticks[left_chopstick]);
        pthread_mutex_lock(&chopsticks[right_chopstick]);
```

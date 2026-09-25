## 19. Thread Synchronization Using Mutex

### Problem Statement

Write a C program to create multiple threads and demonstrate the use of a **mutex** for thread synchronization. The program should initialize a shared counter, create two threads, wait for them to complete, and display the final counter value.

### Program

```c id="3kq8rm"
#include <stdio.h>
#include <pthread.h>

/* Shared variable */
int counter = 0;
pthread_mutex_t mutex;

/* Function to be executed by threads */
void* threadFunction(void* arg)
{
    int i;

    for (i = 0; i < 1000000; i++)
    {
        /* Simulate some work */
    }

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    /* Initialize mutex */
    pthread_mutex_init(&mutex, NULL);

    /* Create threads */
    pthread_create(&thread1, NULL, threadFunction, NULL);
    pthread_create(&thread2, NULL, threadFunction, NULL);

    /* Wait for threads to finish */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    /* Destroy mutex */
    pth
```


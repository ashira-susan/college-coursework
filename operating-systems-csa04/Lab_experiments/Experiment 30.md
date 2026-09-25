## 30. Thread Creation and Thread ID Comparison Using Pthreads

### Problem Statement

Write a C program to create a new thread using `pthread_create()`, compare the thread ID with the current thread ID using `pthread_equal()`, and wait for the created thread to finish using `pthread_join()`.

### Program

```c id="x8h3qa"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* func(void* arg)
{
    printf("Inside the thread\n");

    pthread_exit(NULL);
}

void fun()
{
    pthread_t ptid;

    // Create a new thread
    pthread_create(&ptid, NULL, func, NULL);

    printf("This line may be printed before thread terminates\n");

    // Compare thread IDs
    if (pthread_equal(ptid, pthread_self()))
    {
        printf("Threads are equal\n");
    }
    else
    {
```

## Thread Creation Using Pthreads

### Problem Statement

Write a C program to create **two threads** using the POSIX Threads (`pthread`) library. Each thread should print a different message, and the main program should wait for both threads to complete.

### C Program

```c
#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* arg)
{
    char* message = (char*)arg;

    printf("%s\n", message);

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    char* message1 = "Hello from Thread 1!";
    char* message2 = "Hello from Thread 2!";

    // Create threads
    pthread_create(&thread1, NULL, threadFunction, (void*)message1);
    pthread_create(&thread2, NULL, threadFunction, (void*)message2);

    // Wait for threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
```

### Compilation

Since this program uses the `pthread` library, compile it with:

```bash
gcc program.c -o program -pthread
```

Run it using:

```bash
./program
```

### Sample Output

```text
Hello from Thread 1!
Hello from Thread 2!
```

> **Note:** The order of the two messages is **not guaranteed** because both threads execute concurrently. You may also get:
>
> ```text
> Hello from Thread 2!
> Hello from Thread 1!
> ```
>
> Both outputs are valid.

### Key Functions Used

* `pthread_create()` — creates a new thread.
* `pthread_join()` — waits for a thread to finish.
* `pthread_t` — stores the thread identifier.
* `threadFunction()` — function executed by each thread.

## 29. Producer-Consumer Problem Using Mutex

### Problem Statement

Write a C program to implement the **Producer-Consumer problem** using `mutex`, `full`, and `empty` variables. The producer should add items to the buffer, while the consumer should remove items from the buffer. The program should prevent production when the buffer is full and consumption when the buffer is empty.

### Program

```c id="p7n4qa"
#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10;
int x = 0;

void producer()
{
    --mutex;
    ++full;
    --empty;
    ++x;

    printf("\nProducer produces item %
```

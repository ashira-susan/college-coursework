# Experiment 1: Process ID and Parent Process ID

### Problem Statement

Write a C program to display the **Process ID (PID)** of the current process and its **Parent Process ID (PPID)** using system calls.

### Program

```c id="c2f7xa"
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getpid());

    return 0;
}
```

### Sample Output

```text id="p9k4mz"
Process ID: 12345
Parent Process ID: 12345
```

> The actual ID values will be different each time the program runs.

### Key Concepts

* **Process ID (PID)** → A unique number assigned to a running process.
* `getpid()` → Returns the PID of the current process.
* `getppid()` → Returns the PID of the parent process.
* `unistd.h` → Provides Unix/Linux system calls such as `getpid()` and `getppid()`.

### Important Correction

In the given program, both lines use:

```c
getpid()
```

So the second line actually prints the **current process ID again**, not the parent process ID.

For the correct **Parent Process ID**, use:

```c
getppid()
```

The corrected version is:

```c id="r6t2vn"
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());

    return 0;
}
```

### Correct Sample Output

```text id="x4m8qc"
Process ID: 12345
Parent Process ID: 6789
```

### System Call Flow

```text id="j7w3pk"
Program starts
      ↓
getpid()
      ↓
Current Process ID
      ↓
getppid()
      ↓
Parent Process ID
      ↓
Program ends
```

### Compile and Run

For Linux/WSL:

```bash
gcc program1.c -o program1
./program1
```

**Main concept:** `getpid()` gives the **current process ID**, while `getppid()` gives the **parent process ID**.

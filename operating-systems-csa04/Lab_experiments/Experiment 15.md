##  File Creation in a Directory Using C

### Problem Statement

Write a C program to create a subdirectory path and create a file named `example.txt` inside it. Write sample content into the file and display the file path after successful creation.

### Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char mainDirectory[] = ".";
    char subDirectory[] = "os";
    char fileName[] = "example.txt";

    char filePath[200];
    char mainDirPath[200];

    snprintf(mainDirPath,
             sizeof(mainDirPath),
             "%s/%s/",
             mainDirectory,
             subDirectory);

    snprintf(filePath,
             sizeof(filePath),
             "%s%s",
             mainDirPath,
             fileName);

    FILE *file = fopen(filePath, "w");

    if (file == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    fprintf(file, "This is an example file content.");

    printf("File created successfully: %s\n", filePath);

    fclose(file);

    return 0;
}
```

### Sample Output

```text
File created successfully: ./os/example.txt
```

### File Structure After Execution

```text
current-folder/
├── program.c
└── os/
    └── example.txt
```

### Key Concepts

* `snprintf()` → Builds the directory and file path safely.
* `fopen()` → Creates/opens the file.
* `"w"` → Opens the file for writing; creates it if it does not exist.
* `fprintf()` → Writes content into the file.
* `fclose()` → Closes the file.
* `file == NULL` → Checks whether file creation failed.

> **Note:** The original program used a hard-coded Windows path. The version above uses `"."` so it can run from the current directory in WSL/Linux. The file-creation logic remains the same.

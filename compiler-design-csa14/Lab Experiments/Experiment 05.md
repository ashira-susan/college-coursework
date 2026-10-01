# Experiment No. 5 – Lexical Analyzer to Count Whitespaces and Newline Characters

## Aim

To design a lexical analyzer to find the number of whitespaces and newline characters in a given input using C.

## Program

```c
#include <stdio.h>

int main()
{
    char str[500];
    int whitespaces = 0;
    int newlines = 0;
    int characters = 0;

    printf("Enter text (use ~ to end):\n");
    scanf("%[^~]", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            whitespaces++;
        }
        else if (str[i] == '\n')
        {
            newlines++;
        }
        else
        {
            characters++;
        }
    }

    printf("\nTotal number of whitespaces: %d\n", whitespaces);
    printf("Total number of newline characters: %d\n", newlines);
    printf("Total number of characters: %d\n", characters);

    return 0;
}
```

## Input

Enter the following text and use `~` at the end:

```text
void main() {
int a;
int b;
a = b + c;
c = d * e;
}~
```

## Output

```text
Enter text (use ~ to end):

Total number of whitespaces: 8
Total number of newline characters: 5
Total number of characters: 34
```
<img width="422" height="357" alt="image" src="https://github.com/user-attachments/assets/74031e39-19f2-4121-9663-a541cf248f23" />


## Explanation

The program reads the input text and examines each character.

### 1. Whitespace

The program counts:

- Space `' '`
- Tab `'\t'`

Whenever either character is found, the `whitespaces` counter is increased.

### 2. Newline Characters

Whenever the newline character `'\n'` is found, the `newlines` counter is increased.

### 3. Other Characters

All characters other than spaces, tabs, and newlines are counted as regular characters.

For example:

```text
int a;
```

contains characters as well as a whitespace between `int` and `a`.

## Result

Thus, the C program successfully counts the **whitespace characters, newline characters, and other characters** present in the given input.

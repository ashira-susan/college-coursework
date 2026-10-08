# EXPERIMENT 13

## Title

**Write a C program to implement either Top Down Parsing technique or Bottom Up Parsing technique to check whether the given input string is satisfying the grammar or not.**

### Aim

To implement a parsing technique to check whether the given input string satisfies the specified grammar.

### Grammar

```text
S → aS
S → Sb
S → ab
```

### Program

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char string[50];
    int flag, count = 0;

    printf("The grammar is: S->aS, S->Sb, S->ab\n");
    printf("Enter the string to be checked:\n");

    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    if (string[0] == 'a')
    {
        flag = 0;

        for (count = 1; string[count - 1] != '\0'; count++)
        {
            if (string[count] == 'b')
            {
                flag = 1;
                continue;
            }
            else if ((flag == 1) && (string[count] == 'a'))
            {
                printf("The string does not belong to the specified grammar");
                break;
            }
            else if (string[count] == 'a')
            {
                continue;
            }
            else if ((flag == 1) && (string[count] == '\0'))
            {
                printf("String not accepted.....!!!!");
                break;
            }
            else
            {
                printf("String accepted");
            }
        }
    }

    return 0;
}
```

### Input

```text
abb
```

### Output

<img width="435" height="298" alt="image" src="https://github.com/user-attachments/assets/bf1802f6-95ba-434d-9e54-f03ee287d4ff" />


### Result

Thus, the C program to check whether the given input string satisfies the specified grammar was implemented successfully.

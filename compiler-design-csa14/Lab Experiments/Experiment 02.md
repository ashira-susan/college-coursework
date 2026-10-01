# Experiment No. 2 – Lexical Analyzer for Comment Identification

## Aim

To develop a lexical analyzer using a C program to identify whether a given line is a comment or not.

## Program

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char com[100];
    int i, a = 0;

    printf("Enter comment: ");
    fgets(com, sizeof(com), stdin);

    if (com[0] == '/')
    {
        if (com[1] == '/')
        {
            printf("It is a comment\n");
        }
        else if (com[1] == '*')
        {
            for (i = 2; i < strlen(com) - 1; i++)
            {
                if (com[i] == '*' && com[i + 1] == '/')
                {
                    printf("It is a comment\n");
                    a = 1;
                    break;
                }
            }

            if (a == 0)
            {
                printf("It is not a comment\n");
            }
        }
        else
        {
            printf("It is not a comment\n");
        }
    }
    else
    {
        printf("It is not a comment\n");
    }

    return 0;
}
```
## Output:

<img width="285" height="181" alt="image" src="https://github.com/user-attachments/assets/064e99dc-4407-4a8e-af33-402f4d5088f8" />

<img width="232" height="160" alt="image" src="https://github.com/user-attachments/assets/3ef4c04e-ab7d-4204-b445-704b4f3b3d64" />

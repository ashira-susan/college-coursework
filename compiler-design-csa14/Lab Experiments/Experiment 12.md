# EXPERIMENT 12

## Title

**Write a C program to construct Recursive Descent Parsing for the given grammar**

### Grammar

```text
E  → TE'
E' → +TE' / ∈
T  → FT'
T' → *FT' / ∈
F  → (E) / id
```

### Aim

To write a C program to construct a Recursive Descent Parser for the given grammar.

### Program

```c
#include <stdio.h>
#include <string.h>

char input[100];
int i, l;

int E();
int EP();
int T();
int TP();
int F();

int main()
{
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n");

    printf("\nEnter the string to be checked: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    i = 0;

    if (E())
    {
        if (input[i] == '\0')
            printf("\nString is accepted");
        else
            printf("\nString is not accepted");
    }
    else
    {
        printf("\nString not accepted");
    }

    return 0;
}

int E()
{
    if (T())
    {
        if (EP())
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int EP()
{
    if (input[i] == '+')
    {
        i++;

        if (T())
        {
            if (EP())
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 1;
}

int T()
{
    if (F())
    {
        if (TP())
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int TP()
{
    if (input[i] == '*')
    {
        i++;

        if (F())
        {
            if (TP())
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 1;
}

int F()
{
    if (input[i] == '(')
    {
        i++;

        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else if ((input[i] >= 'a' && input[i] <= 'z') ||
             (input[i] >= 'A' && input[i] <= 'Z'))
    {
        i++;
        return 1;
    }
    else
        return 0;
}
```

### Input

```text
(a+b)*c
a/c+d
```

### Output

<img width="455" height="341" alt="image" src="https://github.com/user-attachments/assets/c01cc0cd-8f9e-423d-9a2c-8fb5660c59b8" />

<img width="456" height="336" alt="image" src="https://github.com/user-attachments/assets/ce049d11-2858-465c-9009-a4ae838974c9" />


### Result

Thus, the C program to construct a Recursive Descent Parser for the given grammar was implemented successfully.

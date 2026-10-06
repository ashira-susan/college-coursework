# Experiment No. 4 – Lexical Analyzer for Operator Validation

## Aim

To design a lexical analyzer to validate and recognize different operators using a C program.

## Program

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char s[5];

    printf("Enter any operator: ");
    fgets(s, sizeof(s), stdin);

    switch (s[0])
    {
        case '>':
            if (s[1] == '=')
                printf("Greater than or equal\n");
            else
                printf("Greater than\n");
            break;

        case '<':
            if (s[1] == '=')
                printf("Less than or equal\n");
            else
                printf("Less than\n");
            break;

        case '=':
            if (s[1] == '=')
                printf("Equal to\n");
            else
                printf("Assignment\n");
            break;

        case '!':
            if (s[1] == '=')
                printf("Not Equal\n");
            else
                printf("Bit Not\n");
            break;

        case '&':
            if (s[1] == '&')
                printf("Logical AND\n");
            else
                printf("Bitwise AND\n");
            break;

        case '|':
            if (s[1] == '|')
                printf("Logical OR\n");
            else
                printf("Bitwise OR\n");
            break;

        case '+':
            printf("Addition\n");
            break;

        case '-':
            printf("Subtraction\n");
            break;

        case '*':
            printf("Multiplication\n");
            break;

        case '/':
            printf("Division\n");
            break;

        case '%':
            printf("Modulus\n");
            break;

        default:
            printf("Not an operator\n");
    }

    return 0;
}
```

## Output

### Test Case 1

```text
Enter any operator: <=
Less than or equal
```
<img width="320" height="202" alt="image" src="https://github.com/user-attachments/assets/b49fd426-1af4-4dcc-8894-bf12b23952e4" />


### Test Case 2

```text
Enter any operator: +
Addition
```
<img width="252" height="160" alt="image" src="https://github.com/user-attachments/assets/5b5eaa30-1b20-46cf-b7b3-b17a2152fb73" />


### Test Case 3

```text
Enter any operator: ==
Equal to
```
<img width="253" height="170" alt="image" src="https://github.com/user-attachments/assets/db0c96f6-bc96-4bc4-98c0-14bd91d4ca6a" />



## Result

Thus, the C program successfully validates and recognizes different arithmetic, relational, logical, and bitwise operators.

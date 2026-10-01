# Experiment No. 1 – Lexical Analyzer

## Aim

To develop a lexical analyzer using a C program to identify **identifiers, constants, and operators** from a given input string.

## Program

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int i, ic = 0, m, cc = 0, oc = 0, j;
    char b[30], operators[30], identifiers[30], constants[30];

    printf("Enter the string: ");
    scanf("%[^\n]", b);

    for (i = 0; i < strlen(b); i++)
    {
        if (isspace(b[i]))
        {
            continue;
        }
        else if (isalpha(b[i]))
        {
            identifiers[ic] = b[i];
            ic++;
        }
        else if (isdigit(b[i]))
        {
            m = b[i] - '0';
            i++;

            while (isdigit(b[i]))
            {
                m = m * 10 + (b[i] - '0');
                i++;
            }

            i--;
            constants[cc] = m;
            cc++;
        }
        else
        {
            if (b[i] == '*')
            {
                operators[oc] = '*';
                oc++;
            }
            else if (b[i] == '-')
            {
                operators[oc] = '-';
                oc++;
            }
            else if (b[i] == '+')
            {
                operators[oc] = '+';
                oc++;
            }
            else if (b[i] == '=')
            {
                operators[oc] = '=';
                oc++;
            }
        }
    }

    printf("Identifiers : ");
    for (j = 0; j < ic; j++)
    {
        printf("%c ", identifiers[j]);
    }

    printf("\nConstants : ");
    for (j = 0; j < cc; j++)
    {
        printf("%d ", constants[j]);
    }

    printf("\nOperators : ");
    for (j = 0; j < oc; j++)
    {
        printf("%c ", operators[j]);
    }

    printf("\n");

    return 0;
}
```
## Output
<img width="391" height="215" alt="image" src="https://github.com/user-attachments/assets/26ee2c70-978c-4dba-9d2f-a93a644d08b2" />

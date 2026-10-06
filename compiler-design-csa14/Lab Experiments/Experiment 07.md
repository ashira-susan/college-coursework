# EXPERIMENT 7

## Title
**Write a C program to find FIRST( ) – Predictive Parser for the given grammar**

### Aim
To write a C program to find the FIRST set of the given grammar using a predictive parser.

### Given Grammar

```text
S → AaAb / BbBa
A → ε
B → ε
```

> In the program, `$` is used to represent ε (epsilon).

### Program

```c
#include <stdio.h>
#include <ctype.h>

void FIRST(char[], char);
void addToResultSet(char[], char);

int numOfProductions;
char productionSet[10][10];

int main()
{
    int i;
    char choice;
    char c;
    char result[20];

    printf("How many number of productions ? :");
    scanf("%d", &numOfProductions);

    for (i = 0; i < numOfProductions; i++)
    {
        printf("Enter productions Number %d : ", i + 1);
        scanf("%s", productionSet[i]);
    }

    do
    {
        printf("\nFind the FIRST of :");
        scanf(" %c", &c);

        FIRST(result, c);

        printf("\nFIRST(%c)= { ", c);

        for (i = 0; result[i] != '\0'; i++)
        {
            printf("%c ", result[i]);
        }

        printf("}\n");

        printf("press 'y' to continue : ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void FIRST(char *Result, char c)
{
    int i, j, k;
    char subResult[20];
    int foundEpsilon;

    subResult[0] = '\0';
    Result[0] = '\0';

    /* If X is a terminal, FIRST(X) = {X}. */
    if (!isupper((unsigned char)c))
    {
        addToResultSet(Result, c);
        return;
    }

    /* If X is a non-terminal */
    for (i = 0; i < numOfProductions; i++)
    {
        /* Find production with X as LHS */
        if (productionSet[i][0] == c)
        {
            /* If X → ε */
            if (productionSet[i][2] == '$')
            {
                addToResultSet(Result, '$');
            }
            else
            {
                j = 2;

                while (productionSet[i][j] != '\0')
                {
                    foundEpsilon = 0;

                    FIRST(subResult, productionSet[i][j]);

                    for (k = 0; subResult[k] != '\0'; k++)
                    {
                        addToResultSet(Result, subResult[k]);
                    }

                    for (k = 0; subResult[k] != '\0'; k++)
                    {
                        if (subResult[k] == '$')
                        {
                            foundEpsilon = 1;
                            break;
                        }
                    }

                    if (!foundEpsilon)
                    {
                        break;
                    }

                    j++;
                }
            }
        }
    }
}

void addToResultSet(char Result[], char val)
{
    int k;

    for (k = 0; Result[k] != '\0'; k++)
    {
        if (Result[k] == val)
        {
            return;
        }
    }

    Result[k] = val;
    Result[k + 1] = '\0';
}
```

### Input

```text
How many number of productions ? :4
Enter productions Number 1 : S=AaAb
Enter productions Number 2 : S=BbBa
Enter productions Number 3 : A=$
Enter productions Number 4 : B=$
```

### Output

```text
Find the FIRST of :S

FIRST(S)= { $ a b }
press 'y' to continue : y

Find the FIRST of :A

FIRST(A)= { $ }
press 'y' to continue : y

Find the FIRST of :B

FIRST(B)= { $ }
press 'y' to continue : n
```
<img width="508" height="466" alt="image" src="https://github.com/user-attachments/assets/51b17df1-6a21-438a-b93e-b207ed4ab9ea" />


### Result

Thus, the C program to find the FIRST set for the given grammar using a predictive parser was successfully executed.

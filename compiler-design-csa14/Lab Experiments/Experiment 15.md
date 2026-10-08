# EXPERIMENT 15

## Title

**Write a C Program to Implement the Operator Precedence Parsing.**

### Aim

To implement the Operator Precedence Parsing technique using C programming.

### Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input;
int i = 0;

char lasthandle[6];
char stack[50];
char handles[][5] = {
    ")E(",
    "E*E",
    "E+E",
    "i",
    "E^E"
};

int top = 0, l;

char prec[9][9] = {
    /*      +    -    *    /    ^    i    (    )    $ */

    /* + */ {'>', '>', '<', '<', '<', '<', '<', '>', '>'},
    /* - */ {'>', '>', '<', '<', '<', '<', '<', '>', '>'},
    /* * */ {'>', '>', '>', '>', '<', '<', '<', '>', '>'},
    /* / */ {'>', '>', '>', '>', '<', '<', '<', '>', '>'},
    /* ^ */ {'>', '>', '>', '>', '<', '<', '<', '>', '>'},
    /* i */ {'>', '>', '>', '>', '>', 'e', 'e', '>', '>'},
    /* ( */ {'<', '<', '<', '<', '<', '<', '<', '>', 'e'},
    /* ) */ {'>', '>', '>', '>', '>', 'e', 'e', '>', '>'},
    /* $ */ {'<', '<', '<', '<', '<', '<', '<', '<', '>'}
};

int getindex(char c)
{
    switch (c)
    {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '^': return 4;
        case 'i': return 5;
        case '(': return 6;
        case ')': return 7;
        case '$': return 8;
    }

    return -1;
}

void shift()
{
    stack[++top] = input[i++];
    stack[top + 1] = '\0';
}

int reduce()
{
    int k, len, found, t;

    for (k = 0; k < 5; k++)
    {
        len = strlen(handles[k]);

        if (stack[top] == handles[k][0] && top + 1 >= len)
        {
            found = 1;

            for (t = 0; t < len; t++)
            {
                if (stack[top - t] != handles[k][t])
                {
                    found = 0;
                    break;
                }
            }

            if (found == 1)
            {
                stack[top - t + 1] = 'E';
                top = top - t + 1;

                strcpy(lasthandle, handles[k]);
                stack[top + 1] = '\0';

                return 1;
            }
        }
    }

    return 0;
}

void dispstack()
{
    printf("%-20s", stack);
}

void dispinput()
{
    char remaining[50];
    int j = 0;

    for (j = i; j < l; j++)
        remaining[j - i] = input[j];

    remaining[j - i] = '\0';

    printf("%-25s", remaining);
}

int main()
{
    input = (char *)malloc(50 * sizeof(char));

    if (input == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    printf("\nEnter the string\n");
    scanf("%49s", input);

    strcat(input, "$");
    l = strlen(input);

    strcpy(stack, "$");

    printf("\n%-20s %-25s %-25s\n",
           "STACK", "INPUT", "ACTION");

    printf("-----------------------------------------------------------------------\n");

    while (i < l - 1)
    {
        shift();

        printf("%-20s ", stack);
        dispinput();
        printf("Shift %c\n", stack[top]);

        if (prec[getindex(stack[top])][getindex(input[i])] == '>')
        {
            while (reduce())
            {
                printf("%-20s ", stack);
                dispinput();
                printf("Reduced: E->%s\n", lasthandle);
            }
        }
    }

    if (strcmp(stack, "$E") == 0)
    {
        printf("%-20s %-25s %-25s\n",
               "$E", "$", "ACCEPT");
    }
    else
    {
        printf("%-20s %-25s %-25s\n",
               stack, "$", "NOT ACCEPTED");
    }

    free(input);

    return 0;
}
```

### Input

```text
i*(i+i)*i
```

### Output
<img width="690" height="652" alt="image" src="https://github.com/user-attachments/assets/2d19d404-d0c0-4195-a0e3-b86ee2340a9e" />


$E                    $                        ACCEPT
```

### Result

Thus, the Operator Precedence Parsing technique was implemented successfully using C programming.

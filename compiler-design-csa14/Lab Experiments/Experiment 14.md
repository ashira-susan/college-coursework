# EXPERIMENT 14

## AIM
To implement the concept of Shift Reduce Parsing in C Programming.

## PROGRAM

```c
#include <stdio.h>
#include <string.h>

char input[20];
char stack[20];
int ip = 0, sp = 0, len;

int main()
{
    printf("\n\t\tSHIFT REDUCE PARSER\n");
    printf("\nGRAMMER\n");
    printf("\nE->E+E");
    printf("\nE->E/E");
    printf("\nE->E*E");
    printf("\nE->a/b");

    printf("\n\nEnter the input symbol: ");
    scanf("%19s", input);

    len = strlen(input);

    printf("\n\t\tSTACK IMPLEMENTATION TABLE\n");
    printf("%-10s %-15s %-15s\n",
           "STACK", "INPUT SYMBOL", "ACTION");

    printf("%-10s %-15s %-15s\n",
           "$", input, "--");

    while (ip < len)
    {
        /* Shift */
        stack[sp++] = input[ip];
        stack[sp] = '\0';

        ip++;

        printf("$%-9s %-15s shift %c\n",
               stack, (input[ip] == '\0' ? "$" : input + ip), stack[sp - 1]);

        /* Reduce terminal to E */
        if (stack[sp - 1] == 'a' || stack[sp - 1] == 'b')
        {
            char terminal = stack[sp - 1];

            stack[sp - 1] = 'E';
            stack[sp] = '\0';

            if (terminal == 'a')
                printf("$%-9s %-15s E->a\n",
                       stack, (input[ip] == '\0' ? "$" : input + ip));
            else
                printf("$%-9s %-15s E->b\n",
                       stack, (input[ip] == '\0' ? "$" : input + ip));
        }

        /* Reduce E operator E */
        if (sp >= 3 &&
            stack[sp - 3] == 'E' &&
            (stack[sp - 2] == '+' ||
             stack[sp - 2] == '/' ||
             stack[sp - 2] == '*') &&
            stack[sp - 1] == 'E')
        {
            char op = stack[sp - 2];

            sp -= 3;
            stack[sp++] = 'E';
            stack[sp] = '\0';

            if (op == '+')
                printf("$%-9s %-15s E->E+E\n",
                       stack, (input[ip] == '\0' ? "$" : input + ip));
            else if (op == '/')
                printf("$%-9s %-15s E->E/E\n",
                       stack, (input[ip] == '\0' ? "$" : input + ip));
            else
                printf("$%-9s %-15s E->E*E\n",
                       stack, (input[ip] == '\0' ? "$" : input + ip));
        }
    }

    if (sp == 1 && stack[0] == 'E')
    {
        printf("$%-9s %-15s ACCEPT\n",
               stack, (input[ip] == '\0' ? "$" : input + ip));
    }
    else
    {
        printf("$%-9s %-15s REJECT\n",
               stack, (input[ip] == '\0' ? "$" : input + ip));
    }

    return 0;
}
```

## INPUT

```text
a+b
```

## OUTPUT

<img width="560" height="657" alt="image" src="https://github.com/user-attachments/assets/48633043-5b8b-46a6-ada0-38743941d36e" />


## RESULT

Thus, the Shift Reduce Parsing technique was implemented successfully.

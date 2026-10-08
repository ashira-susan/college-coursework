# EXPERIMENT 16

## AIM
To generate the Three Address Code representation for the given input statement.

## PROGRAM

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    char tokens[20][10];
    char temp[10];
    int count = 0;
    int i, t = 1;

    printf("Enter the statement: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " ");

    while (token != NULL)
    {
        strcpy(tokens[count], token);
        count++;
        token = strtok(NULL, " ");
    }

    printf("\nThree Address Code:\n");

    strcpy(temp, "t1");

    printf("%s=%s+%s\n", temp, tokens[2], tokens[4]);

    t++;

    for (i = 5; i < count - 1; i += 2)
    {
        sprintf(temp, "t%d", t);

        printf("%s=%s%s%s\n",
               temp,
               (i == 5) ? "t1" : "t2",
               tokens[i],
               tokens[i + 1]);

        t++;
    }

    printf("%s=%s\n", tokens[0], temp);

    return 0;
}
```

## INPUT

```text
out = in1 + in2 + in3 - in4
```

## OUTPUT

<img width="523" height="336" alt="image" src="https://github.com/user-attachments/assets/225efcf7-b253-4b72-8fd9-d3415bcc62b3" />


## RESULT

Thus, the Three Address Code representation was generated successfully.

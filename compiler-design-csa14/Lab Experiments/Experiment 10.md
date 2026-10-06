
# EXPERIMENT 10

## Title

**Implement a C program to eliminate left factoring from a given CFG.**

### Aim

To write a C program to eliminate left factoring from a given Context-Free Grammar (CFG).

### Given Grammar

```text
S → iEtS / iEtSeS / a
E → b
```

### Program

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char gram[50], part1[20], part2[20];
    char modifiedGram[20], newGram[30];
    int i, j, k = 0, pos = 0;

    printf("Enter Production: S->");
    fgets(gram, sizeof(gram), stdin);

    gram[strcspn(gram, "\n")] = '\0';

    /* Extract the first two alternatives */
    for (i = 0, j = 0; gram[i] != '|' && gram[i] != '\0'; i++, j++)
    {
        part1[j] = gram[i];
    }
    part1[j] = '\0';

    if (gram[i] == '|')
        i++;

    for (j = 0; gram[i] != '\0'; i++, j++)
    {
        part2[j] = gram[i];
    }
    part2[j] = '\0';

    /* Find common prefix */
    for (i = 0; part1[i] != '\0' &&
                part2[i] != '\0' &&
                part1[i] == part2[i]; i++)
    {
        modifiedGram[k++] = part1[i];
    }

    pos = i;

    modifiedGram[k++] = 'X';
    modifiedGram[k] = '\0';

    /* Create new production */
    j = 0;

    for (i = pos; part1[i] != '\0'; i++)
    {
        newGram[j++] = part1[i];
    }

    newGram[j++] = '|';

    for (i = pos; part2[i] != '\0'; i++)
    {
        newGram[j++] = part2[i];
    }

    newGram[j] = '\0';

    printf("\nS->%s", modifiedGram);
    printf("\nX->%s\n", newGram);

    return 0;
}
```

### Input

```text
Enter Production: S->iEtS|iEtSeS|a
```

### Output

```text
S->iEtSX
X->|eS|a
```
<img width="400" height="250" alt="image" src="https://github.com/user-attachments/assets/31b7a457-772d-4edc-b1be-025427ceb3d6" />


### Result

Thus, the C program to eliminate left factoring from the given CFG was successfully executed.

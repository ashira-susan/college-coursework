# EXPERIMENT 11

## Title

**Implement a C program to perform symbol table operations.**

### Aim

To write a C program to perform symbol table operations such as insertion, display, search, and modification.

### Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;

struct symtab
{
    char label[20];
    int addr;
} sy[50];

void insert();
int search(char *);
void display();
void modify();

int main()
{
    int ch, val;
    char lab[10];

    do
    {
        printf("\n1.insert\n2.display\n3.search\n4.modify\n5.exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter the label: ");
                scanf("%s", lab);

                val = search(lab);

                if (val == 1)
                    printf("Label is found.");
                else
                    printf("Label is not found.");

                break;

            case 4:
                modify();
                break;

            case 5:
                exit(0);
                break;
        }

    } while (ch < 5);

    return 0;
}

void insert()
{
    int val;
    char lab[10];

    printf("Enter the label: ");
    scanf("%s", lab);

    val = search(lab);

    if (val == 1)
    {
        printf("Duplicate symbol ");
    }
    else
    {
        strcpy(sy[cnt].label, lab);

        printf("Enter the address: ");
        scanf("%d", &sy[cnt].addr);

        cnt++;
    }
}

int search(char *s)
{
    int flag = 0;
    int i;

    for (i = 0; i < cnt; i++)
    {
        if (strcmp(sy[i].label, s) == 0)
            flag = 1;
    }

    return flag;
}

void modify()
{
    int val, ad, i;
    char lab[10];

    printf("Enter the label:");
    scanf("%s", lab);

    val = search(lab);

    if (val == 0)
    {
        printf("No such symbol.");
    }
    else
    {
        printf("Label is found. \n");

        printf("Enter the address:");
        scanf("%d", &ad);

        for (i = 0; i < cnt; i++)
        {
            if (strcmp(sy[i].label, lab) == 0)
                sy[i].addr = ad;
        }
    }
}

void display()
{
    int i;

    for (i = 0; i < cnt; i++)
        printf("%s\t%d\n", sy[i].label, sy[i].addr);
}
```

### Input / Output

```text
1.insert
2.display
3.search
4.modify
5.exit

1. insert
```
<img width="526" height="262" alt="image" src="https://github.com/user-attachments/assets/7a946e5b-dcc0-441a-b856-473669ce63c8" />

```text
2.display
```
<img width="621" height="230" alt="image" src="https://github.com/user-attachments/assets/56acbc82-fc15-46cc-8374-88a449de9288" />

```text
3.search
```
<img width="560" height="182" alt="image" src="https://github.com/user-attachments/assets/f14ff8f8-c4e0-4d52-9b9a-59a1c9e71398" />

```text
4.modify
```
<img width="602" height="443" alt="image" src="https://github.com/user-attachments/assets/c78ff1a6-93a7-4240-9d77-b36142a49921" />


```text
5.exit
```
<img width="495" height="145" alt="image" src="https://github.com/user-attachments/assets/b1481c44-94f1-4b39-a24c-080cf9c6a3c3" />


### Result

Thus, the C program to perform symbol table operations was successfully executed.

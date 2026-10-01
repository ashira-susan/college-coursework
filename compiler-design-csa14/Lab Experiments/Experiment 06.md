# Experiment No. 6 – Lexical Analyzer to Validate an Identifier

## Aim

To develop a lexical analyzer using C to test whether a given identifier is valid or not.

## Program

```c
#include <stdio.h>
#include <ctype.h>

int main()
{
    char a[20];
    int flag = 1;
    int i = 1;

    printf("Enter an identifier: ");
    fgets(a, sizeof(a), stdin);

    /* Check the first character */
    if (isalpha((unsigned char)a[0]))
    {
        while (a[i] != '\0' && a[i] != '\n')
        {
            if (!isdigit((unsigned char)a[i]) &&
                !isalpha((unsigned char)a[i]))
            {
                flag = 0;
                break;
            }

            i++;
        }
    }
    else
    {
        flag = 0;
    }

    if (flag == 1)
    {
        printf("Valid identifier\n");
    }
    else
    {
        printf("Not a valid identifier\n");
    }

    return 0;
}
```

## Output

### Test Case 1 – Valid Identifier

```text
Enter an identifier: abc123
Valid identifier
```
<img width="347" height="177" alt="image" src="https://github.com/user-attachments/assets/d4e25e69-f32b-445c-9a1b-eced48c2c6fb" />


### Test Case 2 – Invalid Identifier

```text
Enter an identifier: 123abc
Not a valid identifier
```
<img width="345" height="173" alt="image" src="https://github.com/user-attachments/assets/4d3b9a88-cf4b-46d6-8cf6-a2924a6afc4c" />


### Test Case 3 – Invalid Identifier

```text
Enter an identifier: abc@123
Not a valid identifier
```
<img width="295" height="185" alt="image" src="https://github.com/user-attachments/assets/9daa389a-8e7a-42a6-89b9-298fcf13270b" />


## Explanation

The program checks whether the given input follows the identifier rules implemented in the program.

### Rules Used

1. The **first character must be an alphabetic character**.
2. The remaining characters can be:
   - Alphabetic characters (`A-Z`, `a-z`)
   - Digits (`0-9`)
3. Special characters such as `@`, `#`, `$`, etc. are not accepted.

### Examples

| Identifier | Result | Reason |
|------------|--------|--------|
| `abc123` | Valid | Starts with a letter and contains letters/digits |
| `hello` | Valid | Contains only letters |
| `abc12` | Valid | Starts with a letter and contains digits |
| `123abc` | Invalid | Starts with a digit |
| `abc@123` | Invalid | Contains `@` |
| `a-b` | Invalid | Contains `-` |

## Result

Thus, the C program successfully tests whether the given identifier is **valid or not** based on the specified lexical rules.

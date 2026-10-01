# Experiment No. 3 – Lexical Analyzer

## Aim

To design a lexical analyzer for a given language that ignores redundant spaces, tabs, new lines, and comments using a C program.

## Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[])
{
    char keywords[32][10] = {
        "main", "auto", "break", "case", "char", "const",
        "continue", "default", "do", "double", "else", "enum",
        "extern", "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "unsigned",
        "void", "printf", "while"
    };

    int i;

    for (i = 0; i < 32; i++)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    char input[] =
        "main ( ) {\n"
        "int a, b, c;\n"
        "c = b + c;\n"
        "printf ( \"%d\", c );\n"
        "}";

    char ch, next;
    char buffer[100];
    char operators[] = "+-*/%=";
    int i, j = 0;
    int length = strlen(input);

    for (i = 0; i < length; i++)
    {
        ch = input[i];

        /* Ignore single-line comments */
        if (ch == '/' && i + 1 < length && input[i + 1] == '/')
        {
            i += 2;

            while (i < length && input[i] != '\n')
            {
                i++;
            }

            continue;
        }

        /* Ignore multi-line comments */
        if (ch == '/' && i + 1 < length && input[i + 1] == '*')
        {
            i += 2;

            while (i + 1 < length &&
                   !(input[i] == '*' && input[i + 1] == '/'))
            {
                i++;
            }

            i++;
            continue;
        }

        /* Identify operators */
        for (int k = 0; k < 6; k++)
        {
            if (ch == operators[k])
            {
                printf("%c is operator\n", ch);
                break;
            }
        }

        /* Identify words */
        if (isalnum((unsigned char)ch) || ch == '_')
        {
            buffer[j++] = ch;
        }
        else if (isspace((unsigned char)ch) && j != 0)
        {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer))
            {
                printf("%s is keyword\n", buffer);
            }
            else
            {
                printf("%s is identifier\n", buffer);
            }
        }
    }

    /* Process the last token */
    if (j != 0)
    {
        buffer[j] = '\0';

        if (isKeyword(buffer))
        {
            printf("%s is keyword\n", buffer);
        }
        else
        {
            printf("%s is identifier\n", buffer);
        }
    }

    return 0;
}
```

## Input File – `flex_input.txt`

Create a file named **`flex_input.txt`** in the same folder as the C program and enter:

```text
main ( ) {
    int a, b, c;
    c = b + c;
    printf ( "%d", c );
}
```

## Output


<img width="290" height="405" alt="image" src="https://github.com/user-attachments/assets/af2bc3b2-fc28-4e67-b172-4c3780dfcf41" />



## Explanation

The lexical analyzer reads the input file character by character and identifies different types of tokens.

### 1. Keywords

The program checks each word against a predefined list of C keywords.

Examples:

```text
main
int
printf
```

are identified as keywords.

### 2. Identifiers

Words that are not present in the keyword list are identified as identifiers.

Examples:

```text
a
b
c
d
```

### 3. Operators

The program identifies the following operators:

```text
+  -  *  /  %  =
```

For example:

```text
c = b + c;
```

produces:

```text
= is operator
+ is operator
```

### 4. Ignoring Spaces, Tabs and New Lines

Spaces, tabs and new lines are treated as separators and are not reported as tokens.

### 5. Ignoring Comments

The program ignores both types of C comments:

```c
// This is a single-line comment
```

and

```c
/* This is a
   multi-line comment */
```

The contents of these comments are not processed as tokens.

## Result

Thus, the C program successfully performs lexical analysis by identifying **keywords, identifiers, and operators**, while ignoring **redundant spaces, tabs, new lines, and comments**.



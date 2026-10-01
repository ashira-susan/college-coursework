# Experiment 20 – String and Numeric Functions in MySQL

## Aim

To implement and execute various string and numeric functions in MySQL.

## Objective

- To perform string manipulation using MySQL string functions.
- To repeat and reverse strings.
- To extract characters from the left and right sides of a string.
- To pad strings with specified characters.
- To obtain ASCII values of characters.
- To convert decimal numbers into binary and octal representations.

## SQL Queries

```sql id="f5x2kn"
SELECT REPLACE('Database Management Systems', 'Management', '');

SELECT REPEAT('DBMS', 10);

SELECT REPEAT(' DBMS ', 10);

SELECT REVERSE('Database');

SELECT RIGHT('Database', 4);

SELECT LEFT('Database', 5);

SELECT RPAD('Database', 14, '#');

SELECT LPAD('Database', 20, '$');

SELECT LPAD('Database', 4, '$');

SELECT ASCII(12);

SELECT ASCII('12');

SELECT ASCII('a');

SELECT BIN(02);

SELECT BIN(11);

SELECT OCT(8);
```

## Concepts Used

- `REPLACE()`
- `REPEAT()`
- `REVERSE()`
- `RIGHT()`
- `LEFT()`
- `RPAD()`
- `LPAD()`
- `ASCII()`
- `BIN()`
- `OCT()`
- String Manipulation
- Number Conversion

## Output

Add the screenshot showing the results of the string and numeric functions here.

<img width="780" height="828" alt="image" src="https://github.com/user-attachments/assets/ae933bac-2149-4828-9abf-0bba7d13252b" />
<img width="777" height="688" alt="image" src="https://github.com/user-attachments/assets/06ba0806-d6ee-4a00-9306-7f207832b93e" />
<img width="772" height="831" alt="image" src="https://github.com/user-attachments/assets/0798ace1-7a7e-4bf0-af81-77053bc7a5bb" />
<img width="767" height="206" alt="image" src="https://github.com/user-attachments/assets/bfda7bba-fd4d-4822-951f-92ea3403bb5c" />


## Conclusion

Thus, various string manipulation and numeric conversion functions were successfully implemented and executed using MySQL.

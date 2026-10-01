# Experiment 21 – Advanced String Functions in MySQL

## Aim

To implement and execute various advanced string functions in MySQL.

## Objective

- To generate spaces using the `SPACE()` function.
- To extract substrings using `SUBSTR()` and `MID()`.
- To convert strings to uppercase and lowercase.
- To remove leading and trailing spaces using trimming functions.
- To determine string length in characters and bits.
- To concatenate strings.
- To locate substrings within strings.
- To determine the position of a substring within a string.

## SQL Queries

```sql id="v5n7cx"
SELECT 'start', SPACE(20), 'end';

SELECT SUBSTR('Database', 5, 4);

SELECT SUBSTR('Database', 5);

SELECT SUBSTR('Database', -5);

SELECT UPPER('Database');

SELECT LOWER('Database');

SELECT TRIM(' DATABASE    ');

SELECT TRIM('      DATABASE         ');

SELECT TRIM(LEADING 'DATABASE' FROM 'DATABASE MANAGEMENT');

SELECT RTRIM('Database          ');

SELECT LTRIM('         Database');

SELECT LENGTH('abc');

SELECT LENGTH(123);

SELECT BIT_LENGTH('abc');

SELECT BIT_LENGTH(2);

SELECT CHAR_LENGTH('abc');

SELECT CHAR_LENGTH(123);

SELECT CONCAT('data', 'base', 'system');

SELECT INSTR('database', 'ab');

SELECT INSTR('database', 'a');

SELECT LOCATE('ab', 'database');

SELECT MID('Database', 5, 4);

SELECT MID('Database', 1, 4);

SELECT POSITION('ta' IN 'Database');
```

## Concepts Used

- `SPACE()`
- `SUBSTR()`
- `UPPER()`
- `LOWER()`
- `TRIM()`
- `RTRIM()`
- `LTRIM()`
- `LENGTH()`
- `BIT_LENGTH()`
- `CHAR_LENGTH()`
- `CONCAT()`
- `INSTR()`
- `LOCATE()`
- `MID()`
- `POSITION()`
- String Manipulation

## Output

Add the screenshot showing the results of the string functions here.

```text id="h3w9kp"
images/experiment-21-output.png
```

## Conclusion

Thus, various string manipulation, extraction, trimming, length, concatenation, and substring search functions were successfully implemented and executed using MySQL.

---

# Capstone Query

## Aim

To create a database and a user table for a Smart Waste Management system.

## SQL Query

```sql id="r6c2mb"
CREATE DATABASE smartwaste;

USE smartwaste;

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    email VARCHAR(100)
);
```

## Output

Add the screenshot showing the successful database and table creation here.

<img width="778" height="835" alt="image" src="https://github.com/user-attachments/assets/25487c92-d7ac-4208-b042-d6b444014c92" />
<img width="772" height="830" alt="image" src="https://github.com/user-attachments/assets/047545c6-5d25-4e6e-ba1c-7e76d2bd18c0" />
<img width="762" height="830" alt="image" src="https://github.com/user-attachments/assets/734a2839-c76f-4b87-9009-f42a59cd20e9" />
<img width="758" height="827" alt="image" src="https://github.com/user-attachments/assets/82026798-ed87-4bf5-8647-417ca8a86b36" />
<img width="767" height="722" alt="image" src="https://github.com/user-attachments/assets/07c6289b-ac2e-4b25-aa67-8d534a81f6b7" />


## Conclusion

Thus, the `smartwaste` database and `users` table were successfully created as the initial structure for the Smart Waste Management capstone project.

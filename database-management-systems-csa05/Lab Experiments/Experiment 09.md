# Experiment 09 – Implementing SQL Joins

## Aim

To create related tables and retrieve data using different types of SQL joins.

## Objective

* To understand the concept of joining tables.
* To perform an `INNER JOIN`.
* To perform an equivalent join using the traditional `WHERE` syntax.
* To perform `LEFT JOIN` and `RIGHT JOIN` operations.
* To perform a `CROSS JOIN`.
* To understand how unmatched records are handled by different joins.

## Description

This experiment demonstrates how data from two related tables can be combined using SQL joins. A `Faculty1` table and a `Department1` table are created with a common `Dept_no` attribute. Different join operations are then performed to retrieve related and unrelated records from the tables.

## SQL Queries

### 1. Create the Faculty1 Table

```sql id="rxz6al"
CREATE TABLE Faculty1 (
    Fac_no INT,
    Fac_name VARCHAR(20),
    Dept_no INT,
    Salary INT
);
```

### 2. Insert Faculty Records

```sql id="e3qg8m"
INSERT INTO Faculty1
VALUES
    (101, 'Gabbie', 1, 50000),
    (102, 'Kevin', 2, 55000),
    (103, 'Andy', 1, 48000);
```

### 3. Create the Department1 Table

```sql id="8x7s3r"
CREATE TABLE Department1 (
    Dept_no INT PRIMARY KEY,
    Dept_name VARCHAR(30)
);
```

### 4. Insert Department Records

```sql id="9d1k2p"
INSERT INTO Department1
VALUES
    (1, 'CSE'),
    (2, 'IT'),
    (3, 'ECE');
```

---

# 5. INNER JOIN

Retrieve faculty names along with their corresponding department names.

```sql id="k5j9x2"
SELECT
    f.Fac_name,
    d.Dept_name
FROM Faculty1 f
INNER JOIN Department1 d
    ON f.Dept_no = d.Dept_no;
```

An `INNER JOIN` returns only the records where a matching `Dept_no` exists in both tables.

### Expected matching records

* Vishnu → CSE
* Shaik → IT
* Andy → CSE

The ECE department does not appear because no faculty member belongs to department 3.

---

# 6. JOIN Using WHERE Clause

The same relationship can be expressed using the traditional join syntax.

```sql id="z0w3pn"
SELECT
    f.Fac_name,
    d.Dept_name
FROM Faculty1 f, Department1 d
WHERE f.Dept_no = d.Dept_no;
```

This produces the same matching results as the `INNER JOIN` above.

---

# 7. LEFT JOIN

Retrieve all faculty members and their corresponding departments.

```sql id="7h2m5k"
SELECT
    f.Fac_name,
    d.Dept_name
FROM Faculty1 f
LEFT JOIN Department1 d
    ON f.Dept_no = d.Dept_no;
```

A `LEFT JOIN` returns **all records from the left table (`Faculty1`)** and matching records from the right table (`Department1`).

---

# 8. CROSS JOIN

Generate every possible combination of faculty members and departments.

```sql id="q8f4ny"
SELECT
    f.Fac_no,
    f.Fac_name,
    d.Dept_name
FROM Faculty1 f
CROSS JOIN Department1 d;
```

Since there are 3 faculty records and 3 department records, the result contains:

**3 × 3 = 9 combinations**

---

# 9. RIGHT JOIN

Retrieve all departments along with matching faculty members.

```sql id="m6v1ps"
SELECT
    f.Fac_name,
    d.Dept_name
FROM Faculty1 f
RIGHT JOIN Department1 d
    ON f.Dept_no = d.Dept_no;
```

A `RIGHT JOIN` returns **all records from the right table (`Department1`)**, including departments that do not have a matching faculty member.

Therefore, the `ECE` department will also appear, with `NULL` for the faculty name.

## Join Types Used

| Join                     | Purpose                                                                     |
| ------------------------ | --------------------------------------------------------------------------- |
| `INNER JOIN`             | Returns matching records from both tables                                   |
| Traditional `WHERE` Join | Performs an equivalent inner join using the older syntax                    |
| `LEFT JOIN`              | Returns all records from the left table and matching records from the right |
| `RIGHT JOIN`             | Returns all records from the right table and matching records from the left |
| `CROSS JOIN`             | Returns every possible combination of rows                                  |

## Concepts Covered

* SQL Joins
* `INNER JOIN`
* `LEFT JOIN`
* `RIGHT JOIN`
* `CROSS JOIN`
* Join conditions
* Table aliases
* Referential relationships
* Cartesian product
* `NULL` values in outer joins

## Output

The output should show the results of each join operation and demonstrate how the returned records differ depending on the type of join used.

<img width="1137" height="257" alt="image" src="https://github.com/user-attachments/assets/09df54a0-3bd9-4821-a143-e81dcbf35ca7" />
<img width="1066" height="571" alt="image" src="https://github.com/user-attachments/assets/58470933-cfed-4169-b1ad-98948e96b446" />
<img width="1107" height="553" alt="image" src="https://github.com/user-attachments/assets/6cedcd0a-ae15-48b9-abc1-5ffe1ede0fcc" />



## Conclusion

Thus, different types of SQL joins were successfully performed to combine and retrieve related data from the `Faculty1` and `Department1` tables.

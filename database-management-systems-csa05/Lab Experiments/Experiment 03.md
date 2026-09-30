# Experiment 03 – Creating and Populating a Faculty Table with Constraints

## Aim

To create a `Faculty` table with appropriate integrity constraints and insert faculty records into the table.

## Objective

* To create a table with different data types.
* To define a primary key and `NOT NULL` constraint.
* To apply `CHECK` constraints to restrict attribute values.
* To insert multiple records into a table using the `INSERT INTO` statement.
* To store faculty details including salary and resignation status.

## Description

This experiment demonstrates the creation and population of a `Faculty` table. Integrity constraints are applied to ensure that the `gender` attribute contains only `M` or `F`, and the `resigned` attribute contains only `Y` or `N`. Multiple faculty records are then inserted into the table.

## SQL Queries

### 1. Create the Faculty Table

```sql
CREATE TABLE Faculty (
    Fac_no INT PRIMARY KEY NOT NULL,
    Fac_name VARCHAR(15),
    gender CHAR(1),
    DOB DATE,
    DOJ DATE,
    mobile_no VARCHAR(10),
    resigned CHAR(1),
    salary INT
);
```

### 2. Add a CHECK Constraint for Gender

```sql
ALTER TABLE Faculty
ADD CONSTRAINT chk_faculty_gender
CHECK (gender = 'M' OR gender = 'F');
```

### 3. Add a CHECK Constraint for Resignation Status

```sql
ALTER TABLE Faculty
ADD CONSTRAINT chk_faculty_resigned
CHECK (resigned = 'Y' OR resigned = 'N');
```

### 4. Insert Faculty Records

```sql
INSERT INTO Faculty
    (Fac_no, Fac_name, gender, DOB, DOJ, mobile_no, resigned, salary)
VALUES
    (1, 'Hari',   'M', '1994-10-24', '2010-05-23', '9447635474', 'Y', 52000),
    (2, 'Ramesh', 'M', '1995-10-24', '2010-06-23', '9475635474', 'Y', 55000),
    (3, 'Kevin',  'M', '1993-02-24', '2010-06-23', '9447638474', 'Y', 60000),
    (4, 'Geeta',  'F', '1996-10-24', '2014-05-23', '9436435474', 'Y', 48000),
    (5, 'Sandy',  'M', '1994-03-12', '2015-07-13', '9438465474', 'N', 50000),
    (6, 'Selvi',  'F', '1993-11-24', '2013-05-23', '9287635474', 'N', 46000),
    (7, 'Kamesh', 'M', '1991-10-24', '2016-02-23', '9342635474', 'Y', 46000);
```

### 5. Display the Faculty Records

```sql
SELECT * FROM Faculty;
```

## Constraints Used

| Constraint    | Purpose                                 |
| ------------- | --------------------------------------- |
| `PRIMARY KEY` | Uniquely identifies each faculty member |
| `NOT NULL`    | Ensures `Fac_no` cannot contain `NULL`  |
| `CHECK`       | Restricts `gender` to `M` or `F`        |
| `CHECK`       | Restricts `resigned` to `Y` or `N`      |

## Concepts Covered

* `CREATE TABLE`
* `ALTER TABLE`
* `INSERT INTO`
* `SELECT`
* Primary key
* `NOT NULL`
* `CHECK` constraint
* Multiple-row insertion
* Date and character data types

## Output

The inserted faculty records can be verified using:

```sql
SELECT * FROM Faculty;
```

<img width="1127" height="670" alt="WhatsApp Image 2026-09-29 at 7 43 15 PM" src="https://github.com/user-attachments/assets/9349cd60-b9cc-43b5-97fa-4d071e101a0b" />


## Conclusion

Thus, the `Faculty` table was successfully created with the required integrity constraints, and the given faculty records were successfully inserted and displayed.

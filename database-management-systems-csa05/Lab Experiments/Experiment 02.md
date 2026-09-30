# Experiment 02 – Implementing SQL Constraints and Foreign Key Relationships

## Aim

To create database tables and implement various SQL constraints such as `PRIMARY KEY`, `NOT NULL`, `CHECK`, `UNIQUE`, and `FOREIGN KEY`.

## Objective

* To define a primary key for uniquely identifying records.
* To apply the `NOT NULL` constraint to mandatory attributes.
* To restrict column values using the `CHECK` constraint.
* To enforce uniqueness using the `UNIQUE` constraint.
* To establish a relationship between two tables using a `FOREIGN KEY`.

## Description

This experiment demonstrates the use of integrity constraints in SQL. A `Faculty` table is created with a primary key and other constraints. A `Department` table is then created, and a foreign key is added to the `Faculty` table to establish a relationship between faculty members and their departments.

## SQL Queries

### 1. Create the Faculty Table

```sql
CREATE TABLE Faculty (
    Fac_no INT PRIMARY KEY NOT NULL,
    Fac_name VARCHAR(15),
    gender CHAR(1),
    DOB DATE,
    mobile_no VARCHAR(15),
    DOJ DATE,
    Dept_no INT
);
```

### 2. Add a CHECK Constraint

Restrict the `gender` column to either `M` or `F`.

```sql
ALTER TABLE Faculty
ADD CONSTRAINT chk_gender
CHECK (gender = 'M' OR gender = 'F');
```

### 3. Add a UNIQUE Constraint

Ensure that each faculty member has a unique name.

```sql
ALTER TABLE Faculty
ADD CONSTRAINT uq_faculty_name
UNIQUE (Fac_name);
```

### 4. Create the Department Table

```sql
CREATE TABLE Department (
    Dept_no INT PRIMARY KEY,
    Dept_name VARCHAR(20)
);
```

### 5. Add a FOREIGN KEY Constraint

Establish a relationship between the `Faculty` and `Department` tables using `Dept_no`.

```sql
ALTER TABLE Faculty
ADD CONSTRAINT fk_faculty_dept
FOREIGN KEY (Dept_no)
REFERENCES Department(Dept_no);
```

## Constraints Used

| Constraint    | Purpose                                             |
| ------------- | --------------------------------------------------- |
| `PRIMARY KEY` | Uniquely identifies each record                     |
| `NOT NULL`    | Prevents a column from containing `NULL` values     |
| `CHECK`       | Restricts values according to a specified condition |
| `UNIQUE`      | Ensures that values in a column are not duplicated  |
| `FOREIGN KEY` | Establishes a relationship between two tables       |

## Concepts Covered

* Data integrity
* Entity integrity
* Referential integrity
* Primary keys
* Candidate/unique constraints
* Domain constraints
* Foreign key relationships
* `ALTER TABLE`

## Output

The successful execution of the queries and creation of the required constraints can be verified using:

```sql
SHOW CREATE TABLE Faculty;
```

and

```sql
SHOW CREATE TABLE Department;
```

<img width="930" height="631" alt="image" src="https://github.com/user-attachments/assets/44a32378-1188-41d5-ad19-e5c6c180d814" />


## Conclusion

Thus, the `Faculty` and `Department` tables were successfully created, and the required SQL integrity constraints were implemented to maintain valid and consistent data.

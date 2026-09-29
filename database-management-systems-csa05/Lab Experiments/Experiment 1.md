# Experiment 01 – Creating and Altering Database Tables

## Aim

To create database tables using SQL and modify the structure of an existing table using the `ALTER TABLE` command.

## Objective

* To create tables using the `CREATE TABLE` statement.
* To define columns with appropriate data types.
* To modify an existing table using `ALTER TABLE`.
* To add a new column to an existing table.

## Description

This experiment demonstrates the creation of three tables — `Faculty`, `Student`, and `Course` — using SQL. It also demonstrates how to modify the structure of an existing table by adding a `dept` column to the `Faculty` table.

## SQL Queries

### 1. Create the Faculty Table

```sql
CREATE TABLE Faculty (
    Fac_no INT,
    Fac_name VARCHAR(15),
    gender CHAR(1),
    DOB DATE,
    mobile_no VARCHAR(15),
    DOJ DATE
);
```

### 2. Alter the Faculty Table

Add the department column to the existing `Faculty` table.

```sql
ALTER TABLE Faculty
ADD dept VARCHAR(10);
```

### 3. Create the Student Table

```sql
CREATE TABLE Student (
    Reg_no INT,
    Name VARCHAR(15),
    Gender CHAR(1),
    DOB DATE,
    mobileno VARCHAR(15),
    city VARCHAR(10)
);
```

### 4. Create the Course Table

```sql
CREATE TABLE Course (
    course_no CHAR(7),
    course_desc VARCHAR(15),
    sem_no INT,
    hall_no INT,
    Faculty_no INT
);
```

## Concepts Covered

* `CREATE TABLE`
* `ALTER TABLE`
* Column definition
* SQL data types
* `INT`
* `VARCHAR`
* `CHAR`
* `DATE`

## Output

The following screenshot shows the successful execution of the table creation and alteration queries.

<img width="566" height="905" alt="image" src="https://github.com/user-attachments/assets/ebd5722b-0b4e-446d-8e33-0521b701b4db" />


## Conclusion

Thus, the required database tables were successfully created using the `CREATE TABLE` statement, and the `Faculty` table was modified successfully using the `ALTER TABLE` statement.

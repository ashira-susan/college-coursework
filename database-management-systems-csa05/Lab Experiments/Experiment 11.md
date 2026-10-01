# Experiment 11 – AUTO_INCREMENT and ALTER TABLE Operations

## Aim

To create and manipulate a student table using `AUTO_INCREMENT`, `UNSIGNED`, `PRIMARY KEY`, and `ALTER TABLE` operations in MySQL.

## Objective

- To create a table with an `AUTO_INCREMENT` primary key.
- To insert records both with and without explicitly specifying the primary key.
- To observe automatically generated registration numbers.
- To describe the structure of the table using `DESC`.
- To modify the table by removing the `AUTO_INCREMENT` primary key column.

## SQL Queries

```sql
CREATE TABLE DBMS_Student (
    Reg_No INT UNSIGNED NOT NULL AUTO_INCREMENT,
    Name VARCHAR(30) NOT NULL,
    Department VARCHAR(30) NOT NULL,
    Mark INT NOT NULL,
    PRIMARY KEY (Reg_No)
);

DESC DBMS_Student;

INSERT INTO DBMS_Student
    (Name, Department, Mark)
VALUES
    ('Raj', 'CSE', 89),
    ('Ramesh', 'ECE', 88),
    ('Rajan', 'CSE', 90),
    ('Rajesh', 'ECE', 85);

SELECT * FROM DBMS_Student;

INSERT INTO DBMS_Student
    (Reg_No, Name, Department, Mark)
VALUES
    (10, 'Aarthi', 'CSE', 89),
    (12, 'Anu', 'ECE', 90),
    (11, 'Anbu', 'ECE', 90);

SELECT * FROM DBMS_Student;

INSERT INTO DBMS_Student
    (Name, Department, Mark)
VALUES
    ('abc', 'CSE', 98),
    ('xyz', 'CSE', 88);

SELECT * FROM DBMS_Student;

INSERT INTO DBMS_Student
    (Name, Department, Mark)
VALUES
    ('AAAAA', 'CSE', 89),
    ('BBBBB', 'ECE', 88),
    ('CCCCC', 'ECE', 88);

SELECT * FROM DBMS_Student;

INSERT INTO DBMS_Student
    (Name, Department, Mark)
VALUES
    ('DD', 'CSE', 89),
    ('EE', 'ECE', 88),
    ('FF', 'ECE', 88);

SELECT * FROM DBMS_Student;

ALTER TABLE DBMS_Student
DROP COLUMN Reg_No;

INSERT INTO DBMS_Student
    (Name, Department, Mark)
VALUES
    ('gggg', 'CSE', 89),
    ('hhhh', 'ECE', 88);

SELECT * FROM DBMS_Student;
```

## Concepts Used

- `CREATE TABLE`
- `AUTO_INCREMENT`
- `UNSIGNED`
- `NOT NULL`
- `PRIMARY KEY`
- `DESC`
- `INSERT INTO`
- Explicit and automatic values
- `SELECT`
- `ALTER TABLE`
- `DROP COLUMN`

## Important Note

`INT(30)` from the original query was changed to `INT`. In MySQL, `(30)` does **not** mean that the column can store 30-digit integers; it is a display-width specification in older MySQL behavior and is unnecessary here.

The queries should be executed **in the given order**, because each `SELECT` is intended to show the changes produced by the preceding `INSERT` or `ALTER TABLE` operation.

## Output

Add the screenshots of the MySQL table structure and query results here.

<img width="802" height="562" alt="image" src="https://github.com/user-attachments/assets/9def8f03-42c9-445e-af23-4dae1820e7f9" />
<img width="815" height="568" alt="image" src="https://github.com/user-attachments/assets/66dc8117-b1aa-45e4-8bab-6f99836e9ebf" />
<img width="807" height="717" alt="image" src="https://github.com/user-attachments/assets/25a26855-dabb-4959-88d9-2ac8370887c9" />
<img width="795" height="527" alt="image" src="https://github.com/user-attachments/assets/e2be5816-b68c-4724-a21a-cf528b45b055" />
<img width="796" height="675" alt="image" src="https://github.com/user-attachments/assets/a3da449c-f739-4bfc-ab23-bb2a5611fb67" />
<img width="808" height="477" alt="image" src="https://github.com/user-attachments/assets/e037588f-1066-4f15-9d07-f4ccfd0df761" />


## Conclusion

Thus, the `DBMS_Student` table was successfully created and manipulated using `AUTO_INCREMENT`, primary key, data insertion, and `ALTER TABLE` operations in MySQL.

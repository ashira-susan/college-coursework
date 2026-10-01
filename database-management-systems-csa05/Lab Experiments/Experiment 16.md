# Experiment 16 – Stored Procedures with IN and OUT Parameters

## Aim

To create and execute MySQL stored procedures using `IN` and `OUT` parameters.

## Objective

- To create and populate a student table.
- To create a stored procedure to display student information.
- To create a stored procedure using an `IN` parameter.
- To use an `OUT` parameter to return a customer classification.
- To implement conditional statements using `IF` and `ELSEIF`.

## SQL Queries

### 1. Student Information Procedure

```sql id="i2x9qk"
CREATE TABLE students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    age INT,
    department VARCHAR(50)
);

INSERT INTO students (name, age, department)
VALUES
    ('John', 20, 'AI & DS'),
    ('Maria', 21, 'CSE'),
    ('David', 22, 'ECE');

DELIMITER //

CREATE PROCEDURE student_info()
BEGIN
    SELECT * FROM students;
END //

DELIMITER ;

CALL student_info();

DROP PROCEDURE IF EXISTS student_info;
```

### 2. Customer Level Procedure

> This procedure requires a `customers` table containing `customerNumber` and `creditlimit` columns. It is therefore intended for a database such as the MySQL sample **Classic Models** database.

```sql id="m8q4tz"
DELIMITER $$

CREATE PROCEDURE GetCustomerLevel(
    IN p_customerNumber INT,
    OUT p_customerLevel VARCHAR(10)
)
BEGIN
    DECLARE creditlim DOUBLE;

    SELECT creditLimit
    INTO creditlim
    FROM customers
    WHERE customerNumber = p_customerNumber;

    IF creditlim > 50000 THEN
        SET p_customerLevel = 'PLATINUM';
    ELSEIF creditlim <= 50000 AND creditlim >= 10000 THEN
        SET p_customerLevel = 'GOLD';
    ELSEIF creditlim < 10000 THEN
        SET p_customerLevel = 'SILVER';
    END IF;
END $$

DELIMITER ;
```

To execute the procedure and view the returned `OUT` value:

```sql
CALL GetCustomerLevel(103, @customerLevel);

SELECT @customerLevel AS Customer_Level;

DROP PROCEDURE IF EXISTS GetCustomerLevel;
```

## Concepts Used

- `CREATE TABLE`
- `AUTO_INCREMENT`
- `PRIMARY KEY`
- `INSERT`
- Stored Procedures
- `IN` parameter
- `OUT` parameter
- `DECLARE`
- `SELECT ... INTO`
- `IF`
- `ELSEIF`
- `SET`
- `CALL`
- `DELIMITER`

## Output

Add the screenshots showing the student information and customer-level procedure results here.

<img width="863" height="777" alt="image" src="https://github.com/user-attachments/assets/2daba80c-7df9-4a78-b6d8-181bd24f8b00" />
<img width="872" height="637" alt="image" src="https://github.com/user-attachments/assets/0ea713dd-94b9-42c7-8020-27ba65f895ee" />


## Conclusion

Thus, MySQL stored procedures using `IN` and `OUT` parameters were successfully created and executed, and conditional statements were used to determine the customer level based on credit limit.

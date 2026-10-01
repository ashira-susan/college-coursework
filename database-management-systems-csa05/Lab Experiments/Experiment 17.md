# Experiment 17 – Stored Function and Recursive Stored Procedure

## Aim

To implement a stored function for customer classification and a recursive stored procedure for calculating factorial in MySQL.

## Objective

- To create a stored function using conditional statements.
- To classify customers based on their credit limit.
- To use a stored function with a `SELECT` statement.
- To create a recursive stored procedure.
- To calculate the factorial of a number using recursion.
- To use `IN` and `OUT` parameters in a stored procedure.

## SQL Queries

### Program 1 – Customer Level Function

```sql id="j3x7qa"
DELIMITER //

CREATE FUNCTION CustomerLevel(p_CREDITLIMIT INT)
RETURNS VARCHAR(10)
DETERMINISTIC
BEGIN
    DECLARE lvl VARCHAR(10);

    IF p_CREDITLIMIT > 50000 THEN
        SET lvl = 'PLATINUM';
    ELSEIF p_CREDITLIMIT <= 50000 AND p_CREDITLIMIT >= 10000 THEN
        SET lvl = 'GOLD';
    ELSE
        SET lvl = 'SILVER';
    END IF;

    RETURN lvl;
END //

DELIMITER ;

SELECT cname, CustomerLevel(CREDITLIMIT)
FROM customer
ORDER BY cname;

DROP FUNCTION IF EXISTS CustomerLevel;
```

### Program 2 – Recursive Factorial Procedure

```sql id="a6k4wp"
DELIMITER $$

CREATE PROCEDURE find_fact(IN n INT, OUT fact INT)
BEGIN
    IF n = 1 THEN
        SET fact = 1;
    ELSE
        CALL find_fact(n - 1, fact);
        SET fact = n * fact;
    END IF;
END $$

DELIMITER ;

SET @@session.max_sp_recursion_depth = 255;

CALL find_fact(5, @result);

SELECT @result AS factorial;

DROP PROCEDURE IF EXISTS find_fact;
```

## Concepts Used

- Stored Functions
- Stored Procedures
- `DETERMINISTIC`
- `IF` and `ELSEIF`
- `RETURN`
- `IN` and `OUT` parameters
- Recursive Procedure
- `CALL`
- Session variables
- `DELIMITER`
- `ORDER BY`

## Output

Add the screenshots showing the customer classification and factorial calculation results here.

<img width="850" height="585" alt="image" src="https://github.com/user-attachments/assets/c559724a-39b2-4996-8b7a-329006c5f053" />

<img width="867" height="706" alt="image" src="https://github.com/user-attachments/assets/2abaf7e8-396b-4ccd-b36d-cab379c739ea" />


## Conclusion

Thus, a stored function was successfully implemented to classify customers based on credit limit, and a recursive stored procedure was used to calculate the factorial of a given number.

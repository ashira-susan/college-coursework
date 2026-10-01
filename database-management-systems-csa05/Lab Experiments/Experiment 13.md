# Experiment 13 – CASE and LOOP Using MySQL Functions

## Aim

To implement `CASE` and `LOOP` statements using MySQL stored functions.

## Objective

- To create a stored function using the `CASE` statement.
- To classify income based on a given monthly value.
- To create a stored function using the `LOOP` statement.
- To use `ITERATE` and `LEAVE` within a loop.
- To execute stored functions using the `SELECT` statement.

## SQL Queries

### CASE

```sql
SET GLOBAL log_bin_trust_function_creators = 1;

DELIMITER //

CREATE FUNCTION IncomeLevel(Monthly_value INT)
RETURNS VARCHAR(20)
BEGIN
    DECLARE income_level VARCHAR(20);

    CASE Monthly_value
        WHEN 4000 THEN
            SET income_level = 'Low Income';
        WHEN 5000 THEN
            SET income_level = 'Avg Income';
        ELSE
            SET income_level = 'High Income';
    END CASE;

    RETURN income_level;
END //

DELIMITER ;

SELECT IncomeLevel(5300);

DROP FUNCTION IF EXISTS IncomeLevel;
```

### LOOP

```sql
DELIMITER //

CREATE FUNCTION CALCINCOME2(starting_value INT)
RETURNS INT
BEGIN
    DECLARE income INT;

    SET income = 0;

    label1: LOOP
        SET income = income + starting_value;

        IF income < 4000 THEN
            ITERATE label1;
        END IF;

        LEAVE label1;
    END LOOP label1;

    RETURN income;
END //

DELIMITER ;

SELECT CALCINCOME2(2100);

DROP FUNCTION IF EXISTS CALCINCOME2;
```

## Concepts Used

- MySQL Stored Functions
- `SET GLOBAL`
- `DELIMITER`
- `CREATE FUNCTION`
- `RETURNS`
- `CASE`
- `LOOP`
- `ITERATE`
- `LEAVE`
- `RETURN`
- `SELECT`
- `DROP FUNCTION`

## Output

Add the screenshots of the MySQL function execution and results here.

<img width="808" height="733" alt="image" src="https://github.com/user-attachments/assets/71fe7653-e8cd-4c11-ab4b-aa0879650d2a" />

<img width="806" height="757" alt="image" src="https://github.com/user-attachments/assets/6911e871-312d-48d9-81b4-4b7d01b892e1" />


## Conclusion

Thus, `CASE` and `LOOP` statements were successfully implemented using MySQL stored functions, and the functions were executed to obtain the required results.

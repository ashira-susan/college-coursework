# Experiment 12 – WHILE and REPEAT Loops

## Aim

To implement and execute `WHILE` and `REPEAT` loops using MySQL stored procedures.

## Objective

- To create a stored procedure using a `WHILE` loop.
- To understand the use of `DELIMITER` in stored procedures.
- To create a stored procedure using a `REPEAT` loop.
- To execute stored procedures using the `CALL` statement.

## SQL Queries

### WHILE Loop

```sql
DELIMITER //

CREATE PROCEDURE test_mysql_while_loop()
BEGIN
    DECLARE x INT;
    DECLARE str VARCHAR(255);

    SET x = 1;
    SET str = '';

    WHILE x <= 5 DO
        SET str = CONCAT(str, x, ',');
        SET x = x + 1;
    END WHILE;

    SELECT str;
END //

DELIMITER ;

CALL test_mysql_while_loop();

DROP PROCEDURE IF EXISTS test_mysql_while_loop;
```

### REPEAT Loop

```sql
DELIMITER //

CREATE PROCEDURE dorepeat(IN p1 INT)
BEGIN
    SET @x = 0;

    REPEAT
        SET @x = @x + 1;
    UNTIL @x > p1
    END REPEAT;
END //

DELIMITER ;

CALL dorepeat(4001);

SELECT @x;

DROP PROCEDURE IF EXISTS dorepeat;
```

## Concepts Used

- Stored Procedures
- `DELIMITER`
- `WHILE` loop
- `REPEAT...UNTIL` loop
- `DECLARE`
- `SET`
- `CONCAT()`
- `CALL`
- `DROP PROCEDURE`

## Output

Add the screenshots of the MySQL procedure execution and results here.

<img width="782" height="666" alt="image" src="https://github.com/user-attachments/assets/f8da017f-7fa6-4699-a327-6c406889e34a" />
<img width="771" height="595" alt="image" src="https://github.com/user-attachments/assets/72a3aaf2-bb3a-4213-862a-cfc06a1cddda" />


## Conclusion

Thus, `WHILE` and `REPEAT` loops were successfully implemented and executed using MySQL stored procedures.

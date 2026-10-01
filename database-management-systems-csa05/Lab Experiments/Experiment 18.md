# Experiment 18 – Using Cursors in MySQL

## Aim

To implement a cursor in MySQL to retrieve and construct a list of employee email addresses.

## Objective

- To create a stored procedure using a cursor.
- To declare and open a cursor.
- To fetch records from a table using the cursor.
- To use a `CONTINUE HANDLER` for detecting the end of the result set.
- To construct an email list using `CONCAT()`.
- To close the cursor after processing all records.

## SQL Queries

```sql id="c4q7wn"
DELIMITER $$

CREATE PROCEDURE build_email_list(INOUT email_list VARCHAR(4000))
BEGIN
    DECLARE v_finished INTEGER DEFAULT 0;
    DECLARE v_email VARCHAR(100) DEFAULT '';

    DECLARE email_cursor CURSOR FOR
        SELECT email FROM employees;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET v_finished = 1;

    OPEN email_cursor;

    get_email: LOOP
        FETCH email_cursor INTO v_email;

        IF v_finished = 1 THEN
            LEAVE get_email;
        END IF;

        SET email_list = CONCAT(v_email, ';', email_list);
    END LOOP get_email;

    CLOSE email_cursor;
END $$

DELIMITER ;

SET @email_list = '';

CALL build_email_list(@email_list);

SELECT @email_list;
```

## Concepts Used

- Stored Procedures
- Cursors
- `INOUT` parameter
- `DECLARE`
- `CURSOR`
- `OPEN`
- `FETCH`
- `CLOSE`
- `LOOP`
- `LEAVE`
- `CONTINUE HANDLER`
- `NOT FOUND`
- `CONCAT()`
- Session Variables
- `DELIMITER`

## Output

Add the screenshot showing the generated employee email list here.

<img width="803" height="887" alt="image" src="https://github.com/user-attachments/assets/e5e98c47-e2df-4743-8da1-dbf62b3200a5" />


## Conclusion

Thus, a MySQL cursor was successfully implemented to fetch employee email addresses and construct them into a single email list using a stored procedure.

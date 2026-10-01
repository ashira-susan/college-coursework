# Experiment 19 – Creating and Using Triggers in MySQL

## Aim

To create and execute a `BEFORE UPDATE` trigger in MySQL to record changes made to student records.

## Objective

- To create an audit table for storing update information.
- To create a `BEFORE UPDATE` trigger.
- To use `OLD` values inside a trigger.
- To automatically record update details in the audit table.
- To verify the trigger execution using a `SELECT` statement.

## SQL Queries

```sql id="e6x3pm"
CREATE TABLE students_audit (
    audit_id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT,
    lastname VARCHAR(100),
    action VARCHAR(50),
    changeat DATETIME
);

DELIMITER //

CREATE TRIGGER before_students_update
BEFORE UPDATE ON students
FOR EACH ROW
BEGIN
    INSERT INTO students_audit
    SET
        action = 'update',
        student_id = OLD.id,
        lastname = OLD.name,
        changeat = NOW();
END //

DELIMITER ;

UPDATE students
SET name = 'Tony Stark_c'
WHERE id = 3;

SELECT * FROM students_audit;
```

## Concepts Used

- Triggers
- `BEFORE UPDATE`
- `CREATE TRIGGER`
- `OLD` keyword
- `FOR EACH ROW`
- Audit Table
- `INSERT`
- `NOW()`
- `DELIMITER`

## Output

Add the screenshot showing the updated student record and corresponding audit entry here.

<img width="812" height="822" alt="image" src="https://github.com/user-attachments/assets/dbc75d36-6106-4a1a-8634-6d0f91f9e858" />


## Conclusion

Thus, a `BEFORE UPDATE` trigger was successfully created to automatically record the previous student information and update details in the audit table whenever a student record is modified.

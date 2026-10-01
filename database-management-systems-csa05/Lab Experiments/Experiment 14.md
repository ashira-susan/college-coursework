# Experiment 14 – Transaction Control Using COMMIT, SAVEPOINT and ROLLBACK

## Aim

To implement transaction control operations using `COMMIT`, `SAVEPOINT`, and `ROLLBACK` in MySQL.

## Objective

- To disable automatic transaction commit using `AUTOCOMMIT`.
- To start a transaction.
- To permanently save changes using `COMMIT`.
- To create savepoints within a transaction.
- To undo changes using `ROLLBACK TO`.
- To observe the effect of rolling back to different savepoints.

## SQL Queries

```sql id="g8r7qa"
SET AUTOCOMMIT = 0;

START TRANSACTION;

CREATE TABLE class (
    name VARCHAR(10),
    id INT
);

INSERT INTO class
VALUES ('dj', 5);

COMMIT;

UPDATE class
SET name = 'bravo'
WHERE id = 5;

SAVEPOINT A;

INSERT INTO class
VALUES ('gopal', 6);

SAVEPOINT B;

INSERT INTO class
VALUES ('balu', 7);

SAVEPOINT C;

SELECT * FROM class;

ROLLBACK TO B;

SELECT * FROM class;

ROLLBACK TO A;

SELECT * FROM class;
```

## Concepts Used

- `AUTOCOMMIT`
- `START TRANSACTION`
- `COMMIT`
- `SAVEPOINT`
- `ROLLBACK TO`
- Transaction Control Language (TCL)
- Transaction management

## Output

Add the screenshots showing the table contents before and after the `ROLLBACK` operations here.

<img width="528" height="762" alt="image" src="https://github.com/user-attachments/assets/c803ef02-ed3a-4f84-b925-440fe859844b" />
<img width="608" height="771" alt="image" src="https://github.com/user-attachments/assets/a660b6b0-3d03-424c-b7e7-0fced8c3b8c2" />
<img width="592" height="197" alt="image" src="https://github.com/user-attachments/assets/c94f84cd-fc84-4150-bc90-94d97569488f" />


## Conclusion

Thus, transaction control operations such as `COMMIT`, `SAVEPOINT`, and `ROLLBACK TO` were successfully implemented and their effects on the database were observed.

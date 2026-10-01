# Experiment 15 – User Creation and Privilege Management

## Aim

To create a MySQL user and manage database privileges using `GRANT` and `SHOW GRANTS`.

## Objective

- To create a new MySQL user.
- To grant specific privileges to the user.
- To understand `SELECT`, `INSERT`, and `UPDATE` privileges.
- To view the privileges assigned to a user.

## SQL Queries

```sql id="f7m3qa"
CREATE USER 'john'@'localhost'
IDENTIFIED BY 'john123';

GRANT SELECT, INSERT, UPDATE
ON Coursework.DBMS_Student
TO 'john'@'localhost';

FLUSH PRIVILEGES;

SHOW GRANTS FOR 'john'@'localhost';
```

## Concepts Used

- `CREATE USER`
- `IDENTIFIED BY`
- `GRANT`
- `SELECT` privilege
- `INSERT` privilege
- `UPDATE` privilege
- `FLUSH PRIVILEGES`
- `SHOW GRANTS`
- Database Security and Access Control

## Output

Add the screenshot showing the user creation and granted privileges here.

<img width="942" height="487" alt="image" src="https://github.com/user-attachments/assets/4ab8a3c5-69d8-40d4-9b18-9a9a152ce640" />


## Conclusion

Thus, a MySQL user was successfully created and granted `SELECT`, `INSERT`, and `UPDATE` privileges on the `DBMS_Student` table, and the assigned privileges were verified using `SHOW GRANTS`.

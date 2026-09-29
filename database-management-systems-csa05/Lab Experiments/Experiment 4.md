# Experiment 04 – Updating and Deleting Records

## Aim

To modify and delete records from a database table using the `UPDATE` and `DELETE` SQL commands.

## Objective

* To update existing records using the `UPDATE` statement.
* To use the `WHERE` clause to identify specific records.
* To delete records using the `DELETE` statement.
* To understand the effect of conditional data modification.

## Description

This experiment demonstrates Data Manipulation Language (DML) operations on the `Faculty` table. The `UPDATE` statement is used to modify the resignation status of a specific faculty member, while the `DELETE` statement removes all faculty records satisfying a specified condition.

## SQL Queries

### 1. Display the Records Before Modification

```sql
SELECT * FROM Faculty;
```

### 2. Update a Faculty Record

Change Kevin's resignation status from `Y` to `N`.

```sql
UPDATE Faculty
SET resigned = 'N'
WHERE Fac_name = 'Kevin';
```

### 3. Verify the Updated Record

```sql
SELECT * FROM Faculty
WHERE Fac_name = 'Kevin';
```

### 4. Delete Faculty Records

Delete all faculty members whose resignation status is `N`.

```sql
DELETE FROM Faculty
WHERE resigned = 'N';
```

### 5. Display the Records After Deletion

```sql
SELECT * FROM Faculty;
```

## Concepts Covered

* `UPDATE`
* `DELETE`
* `SELECT`
* `SET` clause
* `WHERE` clause
* Data Manipulation Language (DML)
* Modifying existing records
* Deleting records based on a condition

## Important Observation

The `UPDATE` operation changes Kevin's `resigned` value to `N`. The subsequent `DELETE` operation removes **every record** whose `resigned` value is `N`, not just Kevin's record.

Therefore, the effect of the `DELETE` statement depends on the existing data in the `Faculty` table.

## Output

The output can be verified by displaying the records before the update, after the update, and after the deletion.

<img width="967" height="795" alt="image" src="https://github.com/user-attachments/assets/15d21c58-c68f-486e-90ae-27a85cff3a73" />


## Conclusion

Thus, the records in the `Faculty` table were successfully modified using the `UPDATE` statement and deleted based on a specified condition using the `DELETE` statement.

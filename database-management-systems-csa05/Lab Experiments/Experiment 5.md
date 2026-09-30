# Experiment 05 – Retrieving Records Using WHERE and LIKE

## Aim

To retrieve specific records from a database table using conditional filtering with the `WHERE` clause and pattern matching with the `LIKE` operator.

## Objective

* To filter records based on a date condition.
* To retrieve records using comparison operators.
* To search for records based on a specified character pattern.
* To use wildcard characters with the `LIKE` operator.

## Description

This experiment demonstrates conditional data retrieval from the `Faculty` table. The first query retrieves faculty members whose date of joining is before a specified date. The second query uses the `LIKE` operator to find faculty names ending with a particular character pattern.

## SQL Queries

### 1. Retrieve Faculty Members Who Joined Before a Specific Date

```sql
SELECT *
FROM Faculty
WHERE DOJ < '2014-02-01';
```

The query retrieves all faculty members whose date of joining (`DOJ`) is earlier than **February 1, 2014**.

### 2. Retrieve Faculty Members Based on a Name Pattern

```sql
SELECT *
FROM Faculty
WHERE Fac_name LIKE '%mesh';
```

The `%` wildcard represents any number of characters before `mesh`.

Therefore, this query retrieves faculty names that **end with `mesh`**, such as `Ramesh` or `Kamesh`.

## Concepts Covered

* `SELECT`
* `WHERE`
* Comparison operators
* Date comparison
* `LIKE` operator
* `%` wildcard
* Conditional data retrieval

## Output

The output shows the faculty records satisfying the specified date and name-pattern conditions.

<img width="936" height="343" alt="image" src="https://github.com/user-attachments/assets/eb790405-d2d1-4880-8ceb-f5145d785caf" />


## Conclusion

Thus, the required faculty records were successfully retrieved using conditional filtering with the `WHERE` clause and pattern matching with the `LIKE` operator.

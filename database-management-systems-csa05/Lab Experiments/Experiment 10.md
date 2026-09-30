# Experiment 10 – Creating Views and Indexes

## Aim

To create and use a SQL view and to demonstrate the creation, analysis, and removal of an index for improving query performance.

## Objective

* To create a view from selected columns of a table.
* To retrieve data through a view.
* To understand the purpose of database indexes.
* To examine a query execution plan using `EXPLAIN`.
* To create an index on a column.
* To compare query execution plans before and after creating an index.
* To remove an existing index.

## Description

This experiment demonstrates two important database concepts: **views** and **indexes**.

A view is a virtual table based on the result of a SQL query. An index is a database structure that can help MySQL locate rows more efficiently when executing queries involving indexed columns. The `EXPLAIN` statement is used to inspect how MySQL plans to execute a query.

---

# Part A – VIEW

## 1. Create a Faculty Summary View

```sql id="z1q6wp"
CREATE VIEW Faculty_summary AS
SELECT
    Fac_name,
    gender,
    salary
FROM Faculty;
```

The view contains a summarized selection of faculty details without creating a separate physical table.

## 2. Retrieve Data from the View

```sql id="c8f4rv"
SELECT * FROM Faculty_summary;
```

This displays the data available through the `Faculty_summary` view.

---

# Part B – INDEX

## 3. Execute a Query Without an Index

Retrieve faculty members whose salary is greater than 50,000.

```sql id="m2x7kd"
SELECT Fac_name
FROM Faculty
WHERE salary > 50000;
```

## 4. Examine the Query Execution Plan

```sql id="p5n3qs"
EXPLAIN
SELECT Fac_name
FROM Faculty
WHERE salary > 50000;
```

The `EXPLAIN` statement shows how MySQL plans to execute the query.

## 5. Create an Index on Salary

```sql id="v7r1hz"
CREATE INDEX index1
ON Faculty(salary);
```

The index is created on the `salary` column.

## 6. Examine the Execution Plan After Creating the Index

```sql id="a4k8mc"
EXPLAIN
SELECT Fac_name
FROM Faculty
WHERE salary > 50000;
```

The execution plan can now be compared with the plan obtained before the index was created.

> **Note:** MySQL may or may not choose to use the new index depending on the table size, data distribution, and optimizer decisions. Creating an index does not guarantee that every query will use it.

## 7. Remove the Index

```sql id="r9d2xt"
DROP INDEX index1
ON Faculty;
```

This removes the `index1` index from the `Faculty` table.

## Concepts Covered

* Views
* `CREATE VIEW`
* Querying a view
* Database indexes
* `CREATE INDEX`
* `EXPLAIN`
* Query execution plans
* `DROP INDEX`
* Query optimization

## Key Difference

| Concept     | Purpose                                                         |
| ----------- | --------------------------------------------------------------- |
| **View**    | Provides a virtual table based on a query                       |
| **Index**   | Provides a data structure that can help speed up data retrieval |
| **EXPLAIN** | Shows the execution plan chosen by the database optimizer       |

## Output

The output should demonstrate:

1. Creation and retrieval of the `Faculty_summary` view.
2. The query execution plan before creating the index.
3. Creation of the `salary` index.
4. The query execution plan after creating the index.
5. Successful removal of the index.

<img width="916" height="427" alt="image" src="https://github.com/user-attachments/assets/55f43491-b7d8-48de-8341-607062610be9" />
<img width="1407" height="563" alt="image" src="https://github.com/user-attachments/assets/9944e55d-b142-4612-91f7-96267c08859b" />


## Conclusion

Thus, a view was successfully created and queried, and an index was created on the `salary` column. The `EXPLAIN` statement was used to examine the query execution plan before and after indexing, and the index was subsequently removed.

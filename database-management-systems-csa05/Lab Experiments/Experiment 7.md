# Experiment 07 – Using GROUP BY, HAVING and ORDER BY

## Aim

To retrieve and organize data from the `Faculty` table using the `GROUP BY`, `HAVING`, and `ORDER BY` clauses.

## Objective

* To group records based on a common attribute.
* To count records within each group.
* To filter grouped results using the `HAVING` clause.
* To sort retrieved records using the `ORDER BY` clause.

## Description

This experiment demonstrates SQL techniques for grouping and organizing query results. The `GROUP BY` clause is used to group faculty members according to their year of joining, while `HAVING` filters groups based on the number of faculty members. The `ORDER BY` clause is used to arrange faculty records according to their faculty number.

## SQL Queries

### 1. Count Faculty Members by Joining Year

```sql id="7h1d3q"
SELECT
    YEAR(DOJ) AS join_year,
    COUNT(*) AS total_faculty
FROM Faculty
GROUP BY YEAR(DOJ);
```

This query groups faculty members according to their year of joining and counts the number of faculty members in each year.

### 2. Find Joining Years with at Least Two Faculty Members

```sql id="0q4j8s"
SELECT
    YEAR(DOJ) AS joined_year,
    COUNT(*) AS total_faculty
FROM Faculty
GROUP BY YEAR(DOJ)
HAVING COUNT(*) >= 2;
```

The `HAVING` clause filters the grouped results and displays only those joining years that have **two or more faculty members**.

### 3. Display Faculty Names and Gender in Faculty Number Order

```sql id="v6m2kx"
SELECT
    Fac_name,
    gender
FROM Faculty
ORDER BY Fac_no;
```

The `ORDER BY` clause sorts the faculty records in ascending order of `Fac_no`.

## Concepts Covered

* `GROUP BY`
* `HAVING`
* `ORDER BY`
* `COUNT()`
* `YEAR()`
* Aggregate functions
* Grouped data filtering
* Sorting query results

## Output

The output shows:

1. The number of faculty members who joined in each year.
2. The joining years having at least two faculty members.
3. Faculty names and gender arranged according to faculty number.

<img width="1218" height="603" alt="image" src="https://github.com/user-attachments/assets/96818115-6fe5-43ce-9496-88e424b006c2" />



## Conclusion

Thus, the `GROUP BY`, `HAVING`, and `ORDER BY` clauses were successfully used to group, filter, count, and sort records in the `Faculty` table.

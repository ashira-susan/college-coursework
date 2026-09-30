# Experiment 08 – Using Subqueries and Correlated Subqueries

## Aim

To retrieve records from the `Faculty` table using subqueries and correlated subqueries.

## Objective

* To understand the use of nested queries.
* To compare individual records with an aggregate value obtained from a subquery.
* To identify faculty members earning more than the overall average salary.
* To use a correlated subquery for comparison within groups.

## Description

This experiment demonstrates the use of subqueries in SQL. The first query uses a subquery to calculate the average salary of all faculty members and retrieves faculty members whose salary is above this average. The second query uses a correlated subquery to compare each faculty member's salary with the average salary of faculty members having the same resignation status.

## SQL Queries

### 1. Faculty Members Earning Above the Overall Average Salary

```sql id="br5v6z"
SELECT
    Fac_name,
    salary
FROM Faculty
WHERE salary > (
    SELECT AVG(salary)
    FROM Faculty
);
```

The inner query calculates the **average salary of all faculty members**. The outer query then retrieves faculty members whose salary is greater than this average.

### 2. Faculty Members Earning Above the Average Salary of Their Resignation Group

```sql id="5gq8sc"
SELECT
    Fac_name,
    salary,
    resigned
FROM Faculty F1
WHERE salary > (
    SELECT AVG(salary)
    FROM Faculty F2
    WHERE F2.resigned = F1.resigned
);
```

This is a **correlated subquery**.

For each faculty member in the outer query (`F1`), the inner query (`F2`) calculates the average salary of faculty members having the **same `resigned` status**. The outer query then displays the faculty member if their salary is above that group average.

## Concepts Covered

* Subqueries
* Nested queries
* Correlated subqueries
* `AVG()` aggregate function
* Table aliases
* Conditional filtering
* Comparison with aggregate results

## Key Difference

| Query   | Comparison                                                                 |
| ------- | -------------------------------------------------------------------------- |
| Query 1 | Faculty salary vs. **overall average salary**                              |
| Query 2 | Faculty salary vs. **average salary of the same resignation-status group** |

## Output

The output shows the faculty members whose salaries satisfy the conditions specified in each query.

<img width="985" height="385" alt="image" src="https://github.com/user-attachments/assets/c987fc79-5fee-4298-9e5c-78c321de733b" />


## Conclusion

Thus, subqueries and correlated subqueries were successfully used to compare faculty salaries with overall and group-specific average salaries.

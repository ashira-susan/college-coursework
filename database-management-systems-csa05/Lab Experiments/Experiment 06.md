# Experiment 06 – Using BETWEEN, IN and Aggregate Functions

## Aim

To retrieve and analyze data from the `Faculty` table using the `BETWEEN` and `IN` operators and SQL aggregate functions.

## Objective

* To calculate the age of faculty members using date functions.
* To filter records within a specified range using `BETWEEN`.
* To filter records matching multiple specified values using `IN`.
* To perform calculations using aggregate functions such as `COUNT`, `AVG`, `MIN`, `MAX`, and `SUM`.
* To perform grouped aggregate operations.

## Description

This experiment demonstrates different SQL techniques for filtering and analyzing data. The `BETWEEN` operator is used to retrieve values within a specified range, while the `IN` operator is used to match values against a list of specified values. Aggregate functions are then used to calculate counts, averages, minimum and maximum values, and totals.

---

## 1. BETWEEN Operator

### 1.1 Display Faculty Details with Calculated Age

```sql id="cb8g8e"
SELECT
    Fac_no,
    Fac_name,
    DOB,
    TIMESTAMPDIFF(YEAR, DOB, CURDATE()) AS age,
    DOJ,
    mobile_no,
    resigned
FROM Faculty;
```

This query calculates the current age of each faculty member using `TIMESTAMPDIFF()`.

### 1.2 Retrieve Faculty Members Between 25 and 30 Years of Age

```sql id="c7w5fz"
SELECT
    Fac_no,
    Fac_name,
    DOB,
    TIMESTAMPDIFF(YEAR, DOB, CURDATE()) AS age
FROM Faculty
WHERE TIMESTAMPDIFF(YEAR, DOB, CURDATE()) BETWEEN 25 AND 30;
```

The `BETWEEN` operator retrieves faculty members whose calculated age is between **25 and 30**, inclusive.

---

## 2. IN Operator

Retrieve faculty members who joined in the years 2013, 2015, or 2016.

```sql id="5g9v9f"
SELECT Fac_name
FROM Faculty
WHERE YEAR(DOJ) IN (2013, 2015, 2016);
```

The `IN` operator allows multiple values to be specified in a single condition.

---

# 3. Aggregate Functions

## 3.1 COUNT()

Count the total number of resigned faculty members.

```sql id="q1i7j4"
SELECT COUNT(*) AS total_resigned
FROM Faculty
WHERE resigned = 'Y';
```

## 3.2 AVG()

Calculate the average age of the faculty members.

```sql id="x9kq3u"
SELECT AVG(TIMESTAMPDIFF(YEAR, DOB, CURDATE())) AS avg_age
FROM Faculty;
```

## 3.3 MIN()

Find the earliest joining date among the faculty members.

```sql id="k1y8t6"
SELECT MIN(DOJ) AS earliest_joined
FROM Faculty;
```

## 3.4 MAX()

Find the latest joining date among the faculty members.

```sql id="v4s2pb"
SELECT MAX(DOJ) AS latest_joined
FROM Faculty;
```

## 3.5 SUM()

Calculate the total salary of all faculty members.

```sql id="0j9k5m"
SELECT SUM(salary) AS total_salary
FROM Faculty;
```

---

## 4. Aggregate Functions with GROUP BY

Find the earliest and latest joining dates separately for resigned and non-resigned faculty members.

```sql id="q3d7hx"
SELECT
    resigned,
    MAX(DOJ) AS latest_joined,
    MIN(DOJ) AS earliest_joined
FROM Faculty
GROUP BY resigned;
```

This groups the faculty records according to their `resigned` status and calculates the minimum and maximum joining dates for each group.

## Concepts Covered

* `BETWEEN`
* `IN`
* `COUNT()`
* `AVG()`
* `MIN()`
* `MAX()`
* `SUM()`
* `TIMESTAMPDIFF()`
* `CURDATE()`
* `YEAR()`
* `GROUP BY`
* Column aliases
* Date functions
* Aggregate functions

## Output

The output screenshots should show the results of the `BETWEEN`, `IN`, aggregate, and grouped aggregate queries.

<img width="1207" height="702" alt="image" src="https://github.com/user-attachments/assets/d926cac8-f66f-4b2e-803d-d0fc88f68e62" />
<img width="1157" height="801" alt="image" src="https://github.com/user-attachments/assets/60547853-42ab-43d2-ace2-dd6bbfe7c5b8" />


## Conclusion

Thus, the `BETWEEN` and `IN` operators were successfully used for conditional data retrieval, and aggregate functions were used to perform statistical calculations on the `Faculty` table.

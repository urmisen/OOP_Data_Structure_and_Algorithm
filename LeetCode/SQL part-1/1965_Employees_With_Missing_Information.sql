-- Table: Employees

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | employee_id | int     |
-- | name        | varchar |
-- +-------------+---------+
-- employee_id is the primary key for this table.
-- Each row of this table indicates the name of the employee whose ID is employee_id.
 

-- Table: Salaries

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | employee_id | int     |
-- | salary      | int     |
-- +-------------+---------+
-- employee_id is the primary key for this table.
-- Each row of this table indicates the salary of the employee whose ID is employee_id.
 

-- Write an SQL query to report the IDs of all the employees with missing information. The information of an employee is missing if:

-- The employee's name is missing, or
-- The employee's salary is missing.
-- Return the result table ordered by employee_id in ascending order.

-- The query result format is in the following example.


-- Query :

SELECT
     employee_id 
FROM
     employees 
WHERE 
     employee_id not IN (SELECT  employee_id FROM salaries )
UNION
SELECT 
     employee_id 
FROM 
     salaries 
WHERE 
     employee_id not IN (SELECT employee_id FROM employees)
ORDER BY 
     employee_id;
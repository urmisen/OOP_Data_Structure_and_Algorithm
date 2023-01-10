-- Table: Employee

-- +-------------+------+
-- | Column Name | Type |
-- +-------------+------+
-- | id          | int  |
-- | salary      | int  |
-- +-------------+------+
-- id is the primary key column for this table.
-- Each row of this table contains information about the salary of an employee.
 

-- Write an SQL query to report the second highest salary from the Employee table. If there is no second highest salary, the query should report null.

-- The query result format is in the following example.

-- Query :

WITH salary_rank AS 
(
    SELECT 
        id,
        salary,
        DENSE_RANK() OVER(ORDER BY salary DESC) as ranking 
    FROM 
        Employee 
) 

SELECT IFNULL(
    
    (SELECT 
        DISTINCT salary 
    FROM 
        salary_rank 
    WHERE 
        ranking = 2
    ), NULL ) 
    
AS SecondHighestSalary 
          
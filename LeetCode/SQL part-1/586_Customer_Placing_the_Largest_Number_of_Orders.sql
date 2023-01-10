-- Table: Orders

-- +-----------------+----------+
-- | Column Name     | Type     |
-- +-----------------+----------+
-- | order_number    | int      |
-- | customer_number | int      |
-- +-----------------+----------+
-- order_number is the primary key for this table.
-- This table contains information about the order ID and the customer ID.
 

-- Write an SQL query to find the customer_number for the customer who has placed the largest number of orders.

-- The test cases are generated so that exactly one customer will have placed more orders than any other customer.


-- Query :

WITH raw AS 
(
    SELECT 
        customer_number,
        RANK() OVER (ORDER BY COUNT(customer_number) DESC) ranking 
    FROM 
        Orders 
    GROUP BY 
        customer_number
)
    
SELECT 
    customer_number 
FROM 
    raw 
WHERE 
    ranking = 1
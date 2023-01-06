-- Table: Products

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | product_id  | int     |
-- | low_fats    | enum    |
-- | recyclable  | enum    |
-- +-------------+---------+
-- product_id is the primary key for this table.
-- low_fats is an ENUM of type ('Y', 'N') where 'Y' means this product is low fat and 'N' means it is not.
-- recyclable is an ENUM of types ('Y', 'N') where 'Y' means this product is recyclable and 'N' means it is not.
 

-- Write an SQL query to find the ids of products that are both low fat and recyclable.

-- Return the result table in any order.

-- The query result format is in the following example.

-- Query :


WITH unbanned_req AS 
(
    SELECT 
        request_at,
        COUNT(id) AS no_of_req,
        COUNT(CASE WHEN status <> 'completed' THEN id ELSE NULL END) AS canceled_req
    FROM 
        Trips   
    WHERE 
        request_at between "2013-10-01" and "2013-10-03"
        AND driver_id IN (SELECT users_id FROM Users WHERE banned = 'No')
        AND client_id IN (SELECT users_id FROM Users WHERE banned = 'No')
    GROUP BY 
        1
)

SELECT 
    request_at AS "Day",
    ROUND(canceled_req/no_of_req,2) AS "Cancellation Rate"
FROM 
    unbanned_req
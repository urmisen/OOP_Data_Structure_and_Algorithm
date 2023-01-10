-- Table: Users

-- +----------------+---------+
-- | Column Name    | Type    |
-- +----------------+---------+
-- | user_id        | int     |
-- | join_date      | date    |
-- | favorite_brand | varchar |
-- +----------------+---------+
-- user_id is the primary key of this table.
-- This table has the info of the users of an online shopping website where users can sell and buy items.
 

-- Table: Orders

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | order_id      | int     |
-- | order_date    | date    |
-- | item_id       | int     |
-- | buyer_id      | int     |
-- | seller_id     | int     |
-- +---------------+---------+
-- order_id is the primary key of this table.
-- item_id is a foreign key to the Items table.
-- buyer_id and seller_id are foreign keys to the Users table.
 

-- Table: Items

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | item_id       | int     |
-- | item_brand    | varchar |
-- +---------------+---------+
-- item_id is the primary key of this table.
 

-- Write an SQL query to find for each user, the join date and the number of orders they made as a buyer in 2019.

-- Return the result table in any order.

-- Query :

WITH raw AS
(
    SELECT 
        buyer_id ,
        item_id
    FROM 
        Orders
    WHERE 
        order_date BETWEEN '2019-01-01' AND  '2019-12-31'
    ORDER BY 
        1 
)

SELECT 
    Users.user_id AS buyer_id ,
    Users.join_date,
    COALESCE(COUNT(raw.item_id),0) AS orders_in_2019
FROM 
    Users
LEFT JOIN 
    raw 
ON 
    Users.user_id = raw.buyer_id
GROUP BY 
    1
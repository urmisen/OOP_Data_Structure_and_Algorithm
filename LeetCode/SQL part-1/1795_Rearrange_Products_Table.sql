-- Table: Products

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | product_id  | int     |
-- | store1      | int     |
-- | store2      | int     |
-- | store3      | int     |
-- +-------------+---------+
-- product_id is the primary key for this table.
-- Each row in this table indicates the product's price in 3 different stores: store1, store2, and store3.
-- If the product is not available in a store, the price will be null in that store's column.
 

-- Write an SQL query to rearrange the Products table so that each row has (product_id, store, price). If a product is not available in a store, do not include a row with that product_id and store combination in the result table.

-- Return the result table in any order.

-- The query result format is in the following example.

-- Query :

SELECT 
    product_id, 'store1' as store, store1 AS price 
FROM 
    products
WHERE 
    store1 IS NOT NULL
UNION
SELECT 
    product_id, 'store2' as store, store2 AS price 
FROM 
    products
WHERE 
    store2 IS NOT NULL
UNION
SELECT 
    product_id, 'store3' as store, store3 AS price 
FROM 
    products
WHERE 
    store3 IS NOT NULL
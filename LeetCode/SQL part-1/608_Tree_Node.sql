-- Table: Tree

-- +-------------+------+
-- | Column Name | Type |
-- +-------------+------+
-- | id          | int  |
-- | p_id        | int  |
-- +-------------+------+
-- id is the primary key column for this table.
-- Each row of this table contains information about the id of a node and the id of its parent node in a tree.
-- The given structure is always a valid tree.
 

-- Each node in the tree can be one of three types:

-- "Leaf": if the node is a leaf node.
-- "Root": if the node is the root of the tree.
-- "Inner": If the node is neither a leaf node nor a root node.
-- Write an SQL query to report the type of each node in the tree.

-- Return the result table in any order.

-- The query result format is in the following example.

WITH parent_node AS 
(
    SELECT 
        DISTINCT p_id 
    FROM 
        Tree
    WHERE 
        p_id IS NOT NULL
)

SELECT 
    id,
    'Root' AS type
FROM 
    Tree 
WHERE 
    p_id IS NULL 

UNION 

SELECT 
    id, 
    'Leaf' AS type 
FROM 
    Tree 
WHERE 
    p_id IS NOT NULL 
AND 
    id NOT IN (SELECT * FROM parent_node)

UNION 

SELECT 
    id, 
    'Inner' AS type 
FROM 
    Tree 
WHERE 
    p_id IS NOT NULL 
AND 
    id IN (SELECT * FROM parent_node)


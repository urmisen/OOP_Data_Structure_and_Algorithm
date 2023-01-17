-- 1. What is the total amount each customer spent at the restaurant?

WITH customer_purchase_data AS
(
SELECT 
     customer_id,
     product_id,
     price
FROM 
     dannys_diner.sales
JOIN 
     dannys_diner.menu
USING(product_id)
)

SELECT 
     customer_id,
     COALESCE(SUM(price),0) AS total_spend
FROM 
     customer_purchase_data 
GROUP BY 
     1 
ORDER BY 
     2 DESC

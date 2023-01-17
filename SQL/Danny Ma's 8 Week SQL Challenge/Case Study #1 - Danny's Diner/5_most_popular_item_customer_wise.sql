-- 5. Which item was the most popular for each customer?
WITH customer_purchase_data AS
(
SELECT 
     customer_id,
     product_id,
     product_name,
     COUNT(*) AS purchase_times,
     DENSE_RANK() OVER(PARTITION BY customer_id ORDER BY COUNT(product_id) DESC) AS item_rank
FROM 
     dannys_diner.sales
JOIN 
     dannys_diner.menu
USING(product_id)
GROUP BY 
     1,2,3
)

SELECT 
     customer_id,
     product_name AS most_purchased_item
FROM 
     customer_purchase_data
WHERE 
     item_rank = 1

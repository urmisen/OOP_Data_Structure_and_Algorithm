-- 6. Which item was purchased first by the customer after they became a member?

WITH customer_purchase_data AS
(
SELECT 
     customer_id,
     product_id,
     product_name,
     order_date,
     DENSE_RANK() OVER(PARTITION BY customer_id ORDER BY DATE(order_date) ASC) AS item_rank
FROM 
     dannys_diner.sales
JOIN 
     dannys_diner.menu
USING(product_id)
JOIN 
     dannys_diner.members 
USING(customer_id)
WHERE 
     DATE(order_date)>= DATE(join_date)
)

SELECT 
     customer_id,
     product_name AS first_purchased_item
FROM 
     customer_purchase_data
WHERE 
     item_rank = 1

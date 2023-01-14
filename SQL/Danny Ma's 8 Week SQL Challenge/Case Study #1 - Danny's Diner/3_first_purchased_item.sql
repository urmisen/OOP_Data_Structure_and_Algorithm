-- 3. What was the first item from the menu purchased by each customer?

WITH customer_purchase_data AS
(
  	SELECT 
        customer_id,
  		product_id,
  		product_name,
  		MIN(order_date) AS first_purchase_date,
        DENSE_RANK() OVER(PARTITION BY customer_id ORDER BY MIN(order_date), product_id) AS item_rank
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
    product_name AS first_purchased_item
FROM 
	customer_purchase_data
WHERE 
	item_rank = 1
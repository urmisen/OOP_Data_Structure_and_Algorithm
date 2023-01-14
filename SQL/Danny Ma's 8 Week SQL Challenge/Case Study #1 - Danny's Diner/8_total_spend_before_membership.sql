-- 8. What is the total items and amount spent for each member before they became a member?

WITH customer_purchase_data AS
(
  	SELECT 
        customer_id,
  		product_id,
  		product_name,
  		order_date,
  		price
    FROM 
        dannys_diner.sales
    JOIN 
        dannys_diner.menu
    USING(product_id)
  	JOIN 
  		dannys_diner.members 
  	USING(customer_id)
  	WHERE 
  		DATE(order_date)< DATE(join_date)
)

SELECT 
	customer_id,
    COALESCE(COUNT(product_id),0) AS total_item_purchased,
    COALESCE(SUM(price),0) AS total_spend
FROM 
	customer_purchase_data
GROUP BY 
	1
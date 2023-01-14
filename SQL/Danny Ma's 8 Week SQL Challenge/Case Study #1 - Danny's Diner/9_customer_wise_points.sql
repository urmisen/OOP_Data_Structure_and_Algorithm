-- 9.  If each $1 spent equates to 10 points and sushi has a 2x points multiplier - how many points would each customer have?

WITH customer_purchase_data AS
(
  	SELECT 
        customer_id,
  		order_date,
  		product_id,
  		product_name,
  		price
    FROM 
        dannys_diner.sales
    JOIN 
        dannys_diner.menu
    USING(product_id)
  	
)

SELECT 
	customer_id,
    SUM(CASE WHEN product_name ILIKE '%sushi%' THEN price*2*10 ELSE price*10 END) AS total_points
FROM 
	customer_purchase_data
GROUP BY 
	1
ORDER BY
	1
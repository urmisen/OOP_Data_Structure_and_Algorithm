-- 10. In the first week after a customer joins the program (including their join date) they earn 2x points on all items, not just sushi - how many points do customer A and B have at the end of January?
WITH customer_purchase_data AS
(
  	SELECT 
        customer_id,
  		join_date,
  		order_date,
  		product_id,
  		product_name,
  		price
    FROM 
        dannys_diner.sales
    JOIN 
        dannys_diner.menu
    USING(product_id)
  	JOIN 
  		dannys_diner.members 
  	USING(customer_id)
  
)

SELECT 
	customer_id,
    SUM(CASE WHEN product_name ILIKE '%sushi%' THEN price*2*10 
        	 WHEN order_date BETWEEN join_date AND (join_date + INTERVAL '6 day') Then price*2*10 
        	 ELSE price*10 
       	END
       ) AS total_points
FROM 
	customer_purchase_data
WHERE 
	order_date < '2021-01-31'
GROUP BY 
	1
ORDER BY
	1
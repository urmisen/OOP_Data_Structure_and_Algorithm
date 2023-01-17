-- 4. What is the most purchased item on the menu and how many times was it purchased by all customers?

WITH product_sell_data AS
(
SELECT 
     product_id,
     product_name,
     COUNT(*) AS purchased_time,
     DENSE_RANK() OVER(ORDER BY COUNT(*) DESC) AS item_rank
FROM 
     dannys_diner.sales
JOIN 
     dannys_diner.menu
USING(product_id)
GROUP BY 
     1,2
)

SELECT 
     product_name AS most_purchased_item,
     purchased_time
FROM 
     product_sell_data
WHERE 
     item_rank = 1

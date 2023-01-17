-- 2. How many days has each customer visited the restaurant?

SELECT 
     customer_id,
     COALESCE(COUNT(DATE(order_date)),0) AS visited_days
FROM 
     dannys_diner.sales
GROUP BY 
     1
ORDER BY 
     2 DESC

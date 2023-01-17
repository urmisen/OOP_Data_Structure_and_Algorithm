CREATE SCHEMA dannys_diner;
SET search_path = dannys_diner;

CREATE TABLE sales (
  "customer_id" VARCHAR(1),
  "order_date" DATE,
  "product_id" INTEGER
);

INSERT INTO sales
  ("customer_id", "order_date", "product_id")
VALUES
  ('A', '2021-01-01', '1'),
  ('A', '2021-01-01', '2'),
  ('A', '2021-01-07', '2'),
  ('A', '2021-01-10', '3'),
  ('A', '2021-01-11', '3'),
  ('A', '2021-01-11', '3'),
  ('B', '2021-01-01', '2'),
  ('B', '2021-01-02', '2'),
  ('B', '2021-01-04', '1'),
  ('B', '2021-01-11', '1'),
  ('B', '2021-01-16', '3'),
  ('B', '2021-02-01', '3'),
  ('C', '2021-01-01', '3'),
  ('C', '2021-01-01', '3'),
  ('C', '2021-01-07', '3');
 

CREATE TABLE menu (
  "product_id" INTEGER,
  "product_name" VARCHAR(5),
  "price" INTEGER
);

INSERT INTO menu
  ("product_id", "product_name", "price")
VALUES
  ('1', 'sushi', '10'),
  ('2', 'curry', '15'),
  ('3', 'ramen', '12');
  

CREATE TABLE members (
  "customer_id" VARCHAR(1),
  "join_date" DATE
);

INSERT INTO members
  ("customer_id", "join_date")
VALUES
  ('A', '2021-01-07'),
  ('B', '2021-01-09');


/* --------------------
   Case Study Questions
   --------------------*/

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

-- 7. Which item was purchased just before the customer became a member?

WITH customer_purchase_data AS
(
SELECT 
     customer_id,
     product_id,
     product_name,
     order_date,
     DENSE_RANK() OVER(PARTITION BY customer_id ORDER BY DATE(order_date) DESC) AS item_rank
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
     product_name AS first_purchased_item
FROM 
     customer_purchase_data
WHERE 
     item_rank = 1

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
     END) AS total_points
FROM 
     customer_purchase_data
WHERE 
     order_date < '2021-01-31'
GROUP BY 
     1
ORDER BY
     1

-- 1) How to find duplicate value in SQL?
SELECT CustomerID, COUNT( * )
FROM order_table
GROUP BY CustomerID
HAVING COUNT( * ) >1;

-- 2) Difference between union and union all ?
-- UNION
SELECT OrderID FROM order_table
UNION
SELECT OrderID FROM order_table_2
ORDER BY OrderID;


-- UNION ALL
SELECT OrderID FROM order_table
UNION ALL
SELECT OrderID FROM order_table_2
ORDER BY OrderID;

-- 3) Difference between inner and left join ?
-- INNER JOIN

SELECT customer.CustomerID, customer.CustomerName, customer.ContactNo, customer.Location, order_table.OrderID, order_table.OrderDate, order_table.ShipperID
FROM customer 
INNER JOIN 
order_table ON customer.CustomerID = order_table.CustomerID;

-- LEFT JOIN

SELECT customer.CustomerID, customer.CustomerName, order_table.OrderID,      
order_table.OrderDate,order_table.ShipperID FROM customer LEFT JOIN order_table ON     
customer.CustomerID = order_table.CustomerID
ON customer.CustomerID = order_table.CustomerID

-- 4) a) How many transactions are successfully done ?

SELECT COUNT(*) as Number_of_Transactions FROM order_details;

-- 4) b) How many products have been sold? And how many order transactions have been completed?

SELECT COUNT(DISTINCT product_id) AS Number_of_sold_products FROM order_details;

SELECT COUNT(DISTINCT order_id) AS Number_of_order_transactions FROM order_details;

-- 4) c) How many users are transactions month on month ? And what is the amount of transactions month on month ?

SELECT  DISTINCT (CONCAT(SUBSTRING_INDEX(order_time,' ',1), 
SUBSTRING_INDEX (SUBSTRING_INDEX(order_time, ',', 2), ',', -1))) as Month_Year, 
Count(DISTINCT user_id) as Number_of_user, 
SUM(REPLACE(transaction_amount, ',', '')) as Sum_transaction 
from order_details GROUP BY Month_Year;


-- 4) d) How many new monthly paid users? 


SELECT  DISTINCT (CONCAT(SUBSTRING_INDEX(order_time,' ',1), 
SUBSTRING_INDEX (SUBSTRING_INDEX(order_time, ',', 2), ',', -1))) as Month_Year,
count(order_details.user_id) as Number_new_paid_user
from order_details 
where order_details.user_id NOT IN (select register_user.id
from register_user )
group by Month_Year;


-- 4) e) How many users are there who have registered but not transacted?

SELECT COUNT(register_user.id) as Number_of_Users FROM register_user
WHERE NOT EXISTS
(SELECT order_details.user_id FROM order_details WHERE register_user.id = order_details.user_id);

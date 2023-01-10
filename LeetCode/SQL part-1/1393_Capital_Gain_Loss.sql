-- Table: Stocks

-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | stock_name    | varchar |
-- | operation     | enum    |
-- | operation_day | int     |
-- | price         | int     |
-- +---------------+---------+
-- (stock_name, operation_day) is the primary key for this table.
-- The operation column is an ENUM of type ('Sell', 'Buy')
-- Each row of this table indicates that the stock which has stock_name had an operation on the day operation_day with the price.
-- It is guaranteed that each 'Sell' operation for a stock has a corresponding 'Buy' operation in a previous day. It is also guaranteed that each 'Buy' operation for a stock has a corresponding 'Sell' operation in an upcoming day.
 

-- Write an SQL query to report the Capital gain/loss for each stock.

-- The Capital gain/loss of a stock is the total gain or loss after buying and selling the stock one or many times.

-- Return the result table in any order.


-- Query :

WITH stock_buy AS 
(
    SELECT 
        stock_name, 
        SUM(price) AS buy_price
    FROM  
        stocks 
    WHERE 
        operation = 'Buy' 
    GROUP BY 
        stock_name
),

stock_sell as 
(
    SELECT 
        stock_name, 
        SUM(price) AS sell_price 
    FROM 
        stocks
    WHERE 
        operation = 'Sell' 
    GROUP BY  
        stock_name
)

SELECT 
    a.stock_name, 
    (a.sell_price-b.buy_price) AS capital_gain_loss 
FROM 
    stock_sell a 
LEFT JOIN 
    stock_buy b 
ON a.stock_name = b.stock_name
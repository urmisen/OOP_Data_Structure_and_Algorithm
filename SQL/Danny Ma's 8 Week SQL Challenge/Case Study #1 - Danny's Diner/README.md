# WEEK - 1
![Author](https://img.shields.io/badge/author-urmisen-orange)
[![Contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/urmisen/Thesis)
[![Stars](https://img.shields.io/github/stars/urmisen/Thesis.svg?style=social)](https://github.com/urmisen/Thesis/stargazers)

# Urmi Sen

Department of Computer Science & Engineering, </br>
Rajshahi University of Engineering & Technology (RUET) </br>
Linkedin: https://www.linkedin.com/in/urmi-sen-78a821149/ </br>
Email: urmisen1202@gmail.com <br>

<hr>

## SQL Challenge By : Danny Ma

## Case Study #1 - Danny's Diner
Thank you Danny Ma for the excellent case study! You can find it in the link below and try it by yourself.
* Link : https://8weeksqlchallenge.com/case-study-1/ </br>

<img src="https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/case_1.PNG" alt="alt text" width="600" height="620">

## Introduction
Danny seriously loves Japanese food so in the beginning of 2021, he decides to embark upon a risky venture and opens up a cute little restaurant that sells his 3 favourite foods: sushi, curry and ramen.

Danny’s Diner is in need of your assistance to help the restaurant stay afloat - the restaurant has captured some very basic data from their few months of operation but have no idea how to use their data to help them run the business.

## Problem Statement
Danny wants to use the data to answer a few simple questions about his customers, especially about their visiting patterns, how much money they’ve spent and also which menu items are their favourite. Having this deeper connection with his customers will help him deliver a better and more personalised experience for his loyal customers.

He plans on using these insights to help him decide whether he should expand the existing customer loyalty program - additionally he needs help to generate some basic datasets so his team can easily inspect the data without needing to use SQL.

Danny has provided you with a sample of his overall customer data due to privacy issues - but he hopes that these examples are enough for you to write fully functioning SQL queries to help him answer his questions!

Danny has shared with you 3 key datasets for this case study:
* sales
* menu
* members

You can inspect the entity relationship diagram and example data below.

### Entity Relationship Diagram
<img src="https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/ER_diagram.PNG" alt="alt text" width="450" height="300">

### Example Datasets
All datasets exist within the dannys_diner database schema - be sure to include this reference within your SQL scripts as you start exploring the data and answering the case study questions.

### Table 1: sales
The sales table captures all customer_id level purchases with an corresponding order_date and product_id information for when and what menu items were ordered.

|       __customer_id__      |       __order_date__         |           __product_id__           |
|----------------------------|------------------------------|------------------------------------|
|             A              |         2021-01-01           |                  1                 | 
|             A              |         2021-01-01           |                  2                 | 
|             A              |         2021-01-07           |                  2                 | 
|             A              |         2021-01-10           |                  3                 | 
|             A              |         2021-01-11           |                  3                 | 
|             A              |         2021-01-11           |                  3                 | 
|             B              |         2021-01-01           |                  2                 |
|             B              |         2021-01-02           |                  2                 |
|             B              |         2021-01-04           |                  1                 |
|             B              |         2021-01-11           |                  1                 |
|             B              |         2021-01-16           |                  3                 |
|             B              |         2021-02-01           |                  3                 |
|             C              |         2021-01-01           |                  3                 | 
|             C              |         2021-01-01           |                  3                 | 
|             C              |         2021-01-07           |                  3                 | 


### Table 2: menu
The menu table maps the product_id to the actual product_name and price of each menu item.

|       __product_id__       |       __product_name__  |           __price__         |
|----------------------------|-------------------------|-----------------------------|
|             1              |         sushi           |               10            | 
|             2              |         curry           |               15            | 
|             3              |         ramen           |               12            | 

### Table 3: members
The final members table captures the join_date when a customer_id joined the beta version of the Danny’s Diner loyalty program.

|       __customer_id__      |       __join_date__     |
|----------------------------|-------------------------|
|             A              |         2021-01-07      |  
|             B              |         2021-01-09      |


## Case Study Questions
Each of the following case study questions can be answered using a single SQL statement:

1. What is the total amount each customer spent at the restaurant?
2. How many days has each customer visited the restaurant?
3. What was the first item from the menu purchased by each customer?
4. What is the most purchased item on the menu and how many times was it purchased by all customers?
5. Which item was the most popular for each customer?
6. Which item was purchased first by the customer after they became a member?
7.  Which item was purchased just before the customer became a member?
8. What is the total items and amount spent for each member before they became a member?
9. If each $1 spent equates to 10 points and sushi has a 2x points multiplier - how many points would each customer have?
10. In the first week after a customer joins the program (including their join date) they earn 2x points on all items, not just sushi - how many points do customer A and B have at the end of January?

## Answer:
I have used PostgreSQL as the programming language and these are the functions that get used
* Aggregate functions — SUM, MIN, MAX
* Windows function - OVER(), DENSE_RANK()
* Joins — INNER JOIN/JOIN, LEFT JOIN
* Common Table Expression (CTE), COALESCE()

## Solutions:
1. https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/1_customer_spend.sql
2. https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/2_visitation_day.sql
3. https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/3_first_purchased_item.sql
4. https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/4_most_purchased_item.sql
5. https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/5_most_popular_item_customer_wise.sql
6. https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/6_first_purchase_after_joining.sql
7. https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/7_last_purchase_before_joining.sql
8. https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/8_total_spend_before_membership.sql
9. https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/9_customer_wise_points.sql
10. https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/10_total_point_after_being_member.sql

* All Question's Solution In One Script : https://github.com/urmisen/OOP_Data_Structure_and_Algorithm/blob/main/SQL/Danny%20Ma's%208%20Week%20SQL%20Challenge/Case%20Study%20%231%20-%20Danny's%20Diner/script.sql


## License
All code in this repository is copyright 2023. All Rights Reserved.

Licensed under the MIT License. You may not use this file except in compliance with the License. Use and/or modification of this code outside of this repository must reference:

## Conclusion:
If you like this repository and please put a star. This will keep me motivated to work more on these. 

## Thank You...!

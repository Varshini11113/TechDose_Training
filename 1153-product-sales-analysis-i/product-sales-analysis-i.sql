# Write your MySQL query statement below
select p.product_name, s.year, s.price from Product as p inner join Sales as s on s.product_id = p.product_id;
# Write your MySQL query statement below
select pd.product_name, sl.year, sl.price from Sales sl left join Product pd on sl.product_id = pd.product_id;
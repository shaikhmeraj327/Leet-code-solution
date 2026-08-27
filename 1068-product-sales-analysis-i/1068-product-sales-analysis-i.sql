# Write your MySQL query statement below
select p.product_name,s.year,s.price from Sales As s left join Product as p on 
s.product_id=p.product_id;

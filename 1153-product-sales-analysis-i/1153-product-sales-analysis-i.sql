# Write your MySQL query statement below
select DISTINCT P.product_name, S.year, S.price
from Sales as S inner join  Product as P USING(product_id);
# Write your MySQL query statement below
select  P.product_name, S.year, S.price
from Sales as S left join  Product as P USING(product_id);
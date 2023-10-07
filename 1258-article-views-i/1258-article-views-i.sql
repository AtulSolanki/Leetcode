# Write your MySQL query statement below
select DISTINCT viewer_id as id from Views where viewer_id = author_id ORDER BY id;
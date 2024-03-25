# Write your MySQL query statement below
select name from Customer WHERE
    COALESCE(referee_id, 0) <> 2
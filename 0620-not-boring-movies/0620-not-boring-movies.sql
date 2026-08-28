# Write your MySQL query statement below
select id,movie,description,rating from Cinema 
where id%2=1 and description!='boring' 
-- And not in(select description from Cinema where description ='boring')
order by rating desc;

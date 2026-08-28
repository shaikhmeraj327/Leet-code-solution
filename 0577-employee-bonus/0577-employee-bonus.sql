# Write your MySQL query statement below
SELECT e.name,b.bonus from employee As e  left join 
Bonus as b on e.empId=b.empId 
where bonus< 1000 or bonus is NULL;

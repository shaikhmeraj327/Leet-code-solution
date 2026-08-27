# Write your MySQL query statement below
SELECT eu.unique_id AS unique_id ,e.name from Employees As e left join EmployeeUNI as eu 
on e.id=eu.id;

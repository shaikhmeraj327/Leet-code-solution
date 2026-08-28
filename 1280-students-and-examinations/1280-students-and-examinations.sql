# Write your MySQL query statement below
select s.student_id,s.student_name,sb.subject_name,count(e.subject_name)
as attended_exams
from Students as s
cross join Subjects as sb 
left join Examinations as e
ON s.student_id = e.student_id
AND sb.subject_name =e.subject_name
group by s.student_id,s.student_name,sb.subject_name
order by s.student_id ASC,sb.subject_name ASc;
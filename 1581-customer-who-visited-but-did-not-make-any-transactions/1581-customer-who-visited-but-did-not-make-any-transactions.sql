SELECT v.customer_id,count(customer_id) As count_no_trans from visits as v left
join transactions as t on v.visit_id=t.visit_id where transaction_id is NULL
group by v.customer_id;

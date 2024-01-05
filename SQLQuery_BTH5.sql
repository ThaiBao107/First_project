create database BTH5
Go

use BTH5
GO


create table salesman
(
	salesman_id char(10),
	name nvarchar(30),
	city nvarchar(30),
	commission decimal(5,2)
	primary key(salesman_id)
)


create table customer
(
	customer_id  char(20),
	cust_name nvarchar(50),
	city nvarchar(50),
	grade int,
	salesman_id char(10)
	primary key(customer_id)
)


create table orders
(
	ord_no char(20),
	purch_amt decimal(5,2),
	ord_date date,
	customer_id char(20),
	salesman_id char(10)
	primary key(ord_no)
)


alter table customer
add foreign key(salesman_id) references salesman(salesman_id)

alter table orders
add foreign key(salesman_id) references salesman(salesman_id)

alter table orders
add foreign key(customer_id) references customer(customer_id)


insert into salesman
(salesman_id ,
	name ,
	city,
	commission)
VALUES('5001','James Hoog','New York',0.15)

insert into salesman
(salesman_id ,
	name ,
	city,
	commission)
VALUES('5002','Nail Knite','Paris',0.13)


insert into salesman
(salesman_id ,
	name ,
	city,
	commission)
VALUES('5003','Pit Alex','London',0.11)


insert into salesman
(salesman_id ,
	name ,
	city,
	commission)
VALUES('5006','Mc Lyon','Paris',0.14)


insert into salesman
(salesman_id ,
	name ,
	commission)
VALUES('5005','Lauson Hen',0.12)

insert into salesman
(salesman_id ,
	name ,
	city,
	commission)
VALUES('5000','Paul Adam','Rome',0.13)

-- insert values for customer table

insert into customer
(
	customer_id  ,
	cust_name ,
	city ,
	grade,
	salesman_id 
)
values('3002','Nick Rimando','New York',100,'5001')



insert into customer
(
	customer_id ,
	cust_name ,
	city ,
	grade ,
	salesman_id 
)
values('3005','Graham zusi','California',200,'5002')

insert into customer
(
	customer_id ,
	cust_name ,
	city ,
	salesman_id 
)
values('3001','Brad Guzan','London','5003')


insert into customer
(
	customer_id ,
	cust_name ,
	city ,
	grade ,
	salesman_id 
)
values('3004','Fabian Johns','Paris',300,'5006')

insert into customer
(
	customer_id ,
	cust_name ,
	city ,
	grade ,
	salesman_id 
)
values('3007','Brad Davis','New York',200,'5001')


insert into customer
(
	customer_id ,
	cust_name ,
	city ,
	grade ,
	salesman_id 
)
values('3009','Geoff Camero','Berlin',100,'5005')


--insert value for orders table

insert into orders
(
	ord_no ,
	purch_amt ,
	ord_date ,
	customer_id ,
	salesman_id
)
values('70001',150.5,'2012-10-05','3005','5002')

insert into orders
(
	ord_no ,
	purch_amt ,
	ord_date ,
	customer_id ,
	salesman_id
)
values('70009',270.65,'2012-09-10','3005','5003')


insert into orders
(
	ord_no ,
	purch_amt ,
	ord_date ,
	customer_id ,
	salesman_id
)
values('70002',65.26,'2012-10-05','3002','5001')


insert into orders
(
	ord_no ,
	purch_amt ,
	ord_date ,
	customer_id ,
	salesman_id
)
values('70004',110.5,'2012-08-17','3009','5005')


insert into orders
(
	ord_no ,
	purch_amt ,
	ord_date ,
	customer_id ,
	salesman_id
)
values('70007',948.5,'2012-09-10','3005','5002')


insert into orders
(
	ord_no ,
	purch_amt ,
	ord_date ,
	customer_id ,
	salesman_id
)
values('70005',2400.6,'2012-07-27','3007','50021')


-- select
--2
select * from customer
where grade > 100

--3
select * from customer
where city = 'New York' and grade > 100

--4
select * from customer
where city ='New York' or grade <= 100

--5


select * from customer
where city != 'New York' and grade <= 100

--6



--7
select S.salesman_id,name,C.city
from salesman AS S,customer AS C
where S.salesman_id = C.salesman_id
and S.commission between 0.1 and 0.12

--8  // xem lai
select * from customer
where city = 'Paris' or city = 'Rome'

--9
select * from salesman
where commission between 0.12 and 0.14

--10
select * from orders
where purch_amt between 500 and 4000 
and purch_amt not in(110.5,948.50)


--11 cau 11
select * from salesman
where name like 'A%'  'L%'


--12
select 8 from salesman
where name not like



--13
select * from customer
where cust_name like 'B%'

--14
select * from customer
where cust_name like '%n'

--15
select * from salesman
where len(name) = 9
and left(name,1) = 'P'
and right(name,1) = 'l'













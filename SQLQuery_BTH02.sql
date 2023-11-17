USE NORTHWND
GO

--1.Viết tích Đề-các giữa 2 bảng Customers và Orders, nhận xét số hàng kết quả. 
--Thêm điều kiện kết, nhận xét số hàng kết quả. 
SELECT * FROM Customers, Orders  
-- 75.530 rows

--2.Lập danh sách các Customer ở thành phố London hoặc ở nước Pháp (France).
--Danh sách gồm: Customer ID, Company Name, Contact Name, Address, City
SELECT CustomerID,CompanyName,ContactName,[Address],[City]
FROM Customers
WHERE Customers.City = 'London' OR Customers.City = 'France'

SELECT City FROM Customers
--6 rows
--3.Lập danh sách các Customer là Sales Manager của nước Mỹ (USA) hoặc là Owner của Mexico.
--Danh sách gồm như trên, thêm cột Contact Title 
SELECT * FROM Customers
SELECT  CustomerID,CompanyName,ContactName,[Address],[City],ContactTitle,Country
FROM Customers
WHERE Customers.ContactTitle = N'Sales Manager' AND Customers.Country = N'USA'
OR Customers.ContactTitle = N'Owner' AND Customers.Country = N'Mexico'
--96 rows
	
--4.Lập danh sách các Customer là Manager của nước Mỹ (USA) hoặc: không phải là Owner của Mexico.
--Danh sách gồm các fields như trên 

SELECT CustomerID,ContactTitle,Country
FROM Customers
WHERE (Customers.ContactTitle like 'M%' AND Customers.Country = N'USA')
OR (Customers.ContactTitle NOT IN ('Owner') AND Customers.Country = N'Mexico')
--6 rows

--5.Lập danh sách các Order có ngày đặt hàng trong 6 tháng đầu năm 1997. 
--Danh sách gồm: Order ID, Order Date, Customer, 
--Employee trong đó Customer là Company Name của khách hàng, Employee lấy Last Name 

SELECT OrderID,OrderDate,CompanyName,LastName
FROM Orders,Customers,Employees
WHERE CAST(MONTH(OrderDate) AS int) <= 6 AND YEAR(OrderDate) = '1997'
AND( Orders.CustomerID = Customers.CustomerID AND  Orders.EmployeeID = Employees.EmployeeID) 
--185 rows
SELECT * FROM Employees

--6.Lập danh sách các Order có ngày đặt hàng trong tháng 2 năm 1997. 
--Danh sách gồm: Order ID, Order Date, CustomerID, EmployeeID.

SELECT OrderID,OrderDate,CustomerID,EmployeeID
FROM Orders
WHERE MONTH(OrderDate) = '2' AND YEAR(OrderDate) = '1997'
--29 rows

--Danh sách các Order có Ship Country là UK do nhân viên có mã là 2 phụ trách trong năm 1997.
--Danh sách gồm:   Order ID, Order Date, Freight 

SELECT OrderID,OrderDate,Freight,ShipCountry
FROM Orders
WHERE (Orders.ShipCountry = 'UK' AND YEAR(Orders.OrderDate) = '1997')

-- 30 rows

--8.Người ta muốn biết danh sách các sản phẩm có tên bắt đầu là Ch.
--Anh chi hãy lập danh sách này, gồm các cột: Product ID, Product Name.
SELECT ProductID,ProductName
FROM Products
WHERE Products.ProductName like 'Ch%'

--6 rows
--9.Lập danh sách các sản phẩm không còn tiếp tục cung cấp nữa (trường Discontinued) và có số lượng tồn kho (trường Unit In stock) lớn hơn không.
--Danh sách gồm: Product ID, Unit Price, Unit In Stock.

SELECT ProductID,UnitPrice,UnitsInStock,Discontinued
FROM Products
WHERE Products.Discontinued = '0' AND Products.UnitsInStock > 0

SELECT * FROM Products
--68 rows

--10.Lập danh sách các khách hàng không thuộc nước Mỹ. 
--Danh sách gồm: Company Name, Contact Name, Country, Phone, Fax 

SELECT CompanyName,ContactName,Country,Phone,Fax
FROM Customers
WHERE Customers.Country <> 'USA' --'<>' different

SELECT * FROM Customers
-- 78 rows

--11.Lập danh sách các khách hàng không thuộc các nước Brazil, Italy, Spain, Venezuela và UK.
--Danh sách gồm: Company Name, Contact Name, Country, Phone, Fax 
--Cach 1:
SELECT CompanyName,ContactName,Country,Phone,Fax
FROM Customers
WHERE Customers.Country <> 'Brazil' AND Customers.Country <> 'Italy'
AND Customers.Country <> 'Spain' AND Customers.Country <> 'Venezuela' AND Customers.Country <> 'UK'
--Cach 2:
SELECT CompanyName,ContactName,Country,Phone,Fax
FROM Customers
WHERE Customers.Country NOT IN ('Brazil','Italy','Spain','Venezuela','UK')

-- 63 rows
--12.Lập danh sách các đơn đặt hàng có Ship country là USA và có Freight > 300 hoặc các đơn có Ship Country là Argentina và Freight <5. 
--Danh sách gồm: Order ID, Customer, Employee, Order date, Ship Country, Ship date, Freight 

SELECT OrderID,CustomerID,EmployeeID,OrderDate,ShipCountry,ShippedDate,Freight
FROM Orders
WHERE (Orders.ShipCountry = 'USA' AND Orders.Freight > 300) 
OR (Orders.ShipCountry = 'Argentina' AND Orders.Freight < 5)
-- 16 rows

--14.Lập danh sách các đơn hàng trong tháng 4/97 gồm các thông tin sau: 
--Order ID, Order Date, Customer, Employee, Freight, New-Freight trong đó New-Freight =110% Freight.

SELECT OrderID,OrderDate,CustomerID,EmployeeID,format(Freight * 1.1,'N1') AS Freight
FROM Orders
WHERE MONTH(OrderDate) = '4' AND YEAR(OrderDate) = '1997' 
--31 rows

--15.	Lập danh sách trị giá tồn kho các Product không còn tiếp tục cung cấp nữa (trường 
--Discontinued là Yes). Danh sách gồm: Product ID, Product Name, Supplier Name, 
--UnitPrice, 	UintsInStock, 	Total, 	Supplier 	Fax, 	trong 	đó 	Total 	= UnitPrice*UnitsInStock

SELECT ProductID,ProductName,Products.SupplierID ,UnitPrice,UnitsInStock,(UnitPrice*UnitsInStock) AS Total
FROM Products,Suppliers
WHERE (Products.SupplierID = Suppliers.SupplierID)
AND (Products.Discontinued = '1')
--8 rows

--16.Lập danh sách nhân viên (Table Employee) có hire date từ năm 1993 trở về trước.
--Danh sách gồm: Name, Hire date, Title, BirthDate, Home Phone, 
--trong đó trường Name ghép từ các trường: TitleOfCourstesy, chữ đầu trường LastName và trường FirstName

SELECT (TitleOfCourtesy + '.' + LastName + ' ' + FirstName) AS Name,HireDate,Title,BirthDate,HomePhone
FROM Employees
WHERE YEAR(HireDate) <= 1993


--17.	Lập danh sách các Order có ngày đặt hàng trong tháng 4 hàng năm.
--Danh sách gồm: Order ID, Order Date, Customer,
--Employee trong đó Customer là Company Name của khách hàng, Employee lấy Last Name 
SELECT OrderId,OrderDate,LastName
FROM Customers,Orders,Employees
WHERE Customers.CustomerID =  Orders.CustomerID 
AND Orders.EmployeeID = Employees.EmployeeID
AND MONTH(OrderDate) = 4


--18.	Lập danh sách các Order có ngày đặt hàng các năm chẳn.
--Danh sách gồm: Order ID, Order Date, Customer,
--Employee trong đó Customer là Company Name của khách hàng, Employee lấy Last Name 
SELECT OrderID,OrderDate,CompanyName,LastName
FROM Customers,Employees,Orders
WHERE Customers.CustomerID = orders.CustomerID AND Orders.EmployeeID = Employees.EmployeeID
AND (Year(OrderDate) % 2 = 0)
-- 422 rows
--------------------------------------------------------------------------------------
--19 111 rows
-- 105 row
-------------------------------------------------------------------------------------

--20 --1059 rows
SELECT O.OrderID,ProductName,O.UnitPrice,Quantity,(O.UnitPrice * Quantity) AS ThanhTien,
(O.UnitPrice * Quantity * Discount) AS TiemGiamGia, ((O.UnitPrice * Quantity) - (O.UnitPrice * Quantity * Discount))
FROM Products,[Order Details] AS O, Orders
WHERE Products.ProductID = O.ProductID
AND Orders.OrderID = O.OrderID
AND YEAR(Orders.OrderDate) = 1997



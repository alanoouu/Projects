/* Question 1*/
SELECT firstName, lastName
FROM Customer
WHERE income > 80000
ORDER BY lastName, firstName

/* Question 2*/
SELECT branchName, accNumber, balance
FROM Branch, Account
WHERE balance > 115000 AND 
		budget > 2000000
ORDER BY branchName, accNumber

/* Question 3*/
SELECT DISTINCT C.firstName, C.lastName, C.income
FROM Customer C, Customer CS
WHERE C.income / 2 > ANY
		(SELECT Charles.income
		FROM Customer Charles
		WHERE Charles.firstName = 'Charles' AND
				Charles.lastName = 'Smith')
ORDER BY lastName, firstName

/* Question 4*/
SELECT C1.customerID, C1.income, A1.accNumber, A1.branchNumber
FROM Customer C1, Account A1, Owns O1, Branch B1
WHERE C1.customerID = O1.customerID AND
		O1.accNumber = A1.accNumber AND 
		A1.branchNumber = B1.branchNumber AND C1.customerID IN (
				SELECT C2.customerID
				FROM Customer C2, Account A2, Owns O2, Branch B2
				WHERE C2.customerID = O2.customerID AND
						O2.accNumber = A2.accNumber AND
						A2.branchNumber = B2.branchNumber AND
						(B2.branchName = 'London' OR B2.branchName = 'Latveria'))		
ORDER BY C1.customerID, A1.accNumber

/* Question 5*/
SELECT C.customerID, A1.type, A1.accNumber, A1.balance
FROM Customer C, Owns O1, Account A1,
Owns O2, Account A2
WHERE C.customerID = O1.customerID AND
O1.customerID = O2.customerID AND
O1.accNumber = A1.accNumber AND
O2.accNumber = A2.accNumber AND
A1.type = 'bus' AND
A2.type = 'sav'
UNION 
SELECT C.customerID, A2.type, A2.accNumber, A2.balance
FROM Customer C, Owns O1, Account A1,
Owns O2, Account A2
WHERE C.customerID = O1.customerID AND
O1.customerID = O2.customerID AND
O1.accNumber = A1.accNumber AND
O2.accNumber = A2.accNumber AND
A1.type = 'bus' AND
A2.type = 'sav'
ORDER BY C.customerID, A1.type, A1.accNumber

/* Question 6*/
SELECT DISTINCT E.sin, B.branchName, E.salary, E.salary - M.salary AS employee_salary_minus_manager_salary
FROM Employee E, Employee M, Branch B
WHERE E.branchNumber = B.branchNumber AND M.sin IN 
		(SELECT B2.managerSIN
		FROM Branch B2
		WHERE E.branchNumber = M.branchNumber)
ORDER BY employee_salary_minus_manager_salary DESC

/* Question 7*/
SELECT O1.customerID
FROM Owns O1, Account A1, Branch B1
WHERE A1.accNumber = O1.accNumber AND
		A1.branchNumber = B1.branchNumber AND
		B1.branchName = 'Berlin'
EXCEPT 
SELECT O2.customerID
FROM Owns O2, Account A2, Branch B2
WHERE A2.accNumber = O2.accNumber AND
		A2.branchNumber = B2.branchNumber AND
		B2.branchName = 'London'
ORDER BY O1.customerID

/* Question 8*/
SELECT E.sin, E.lastName, E.salary, B.branchName FROM Employee E
LEFT OUTER JOIN Branch B ON E.sin = B.managerSIN 
WHERE salary > 80000
ORDER BY E.salary DESC

/* Question 9*/
SELECT E1.sin, E1.lastName, E1.salary, B.branchName
FROM Employee E1, Branch B
WHERE salary > 80000 AND E1.sin = B.managerSIN
UNION
SELECT E2.sin, E2.lastName, E2.salary, NULL
FROM Employee E2, Branch B2
WHERE salary > 80000 AND E2.sin NOT IN (SELECT B3.managerSIN
			FROM Branch B3)
ORDER BY E1.salary DESC

/* Question 10*/
SELECT DISTINCT C.customerID, C.lastName, C.birthDate
FROM Customer C, Owns O, Account A
WHERE C.customerID = O.customerID AND 
		O.accNumber = A.accNumber AND
		A.branchNumber = ANY (SELECT A3.branchNumber FROM Customer C3, Owns O3, Account A3
							 WHERE C3.firstName = 'Adam' AND C3.lastName = 'Rivera' AND C3.customerID = O3.customerID
							 AND O3.accNumber = A3.accNumber) 

UNION
SELECT DISTINCT C.customerID , C.lastName, C.birthDate
FROM Customer C, Owns O, Account A
WHERE C.customerID = O.customerID AND 
		O.accNumber = A.accNumber AND
		A.branchNumber = ANY (SELECT A3.branchNumber FROM Customer C3, Owns O3, Account A3
							 WHERE C3.firstName = 'Adam' AND C3.lastName = 'Rivera' AND C3.customerID = O3.customerID
							 AND O3.accNumber = A3.accNumber) 

ORDER BY C.customerID

/* Question 11*/
SELECT E1.sin, E1.firstName, E1.lastName, E1.salary 
FROM Employee E1, Branch B
WHERE E1.branchNumber = B.branchNumber AND 
		B.branchName = 'Berlin' AND 
		E1.salary = (SELECT MAX (E2.salary) 
						FROM Employee E2 
						WHERE E2.branchNumber = B.branchNumber AND 
							B.branchName = 'Berlin')
ORDER BY sin

/* Question 12*/
SELECT SUM (E.salary) AS sum_salary
FROM Employee E, Branch B
WHERE E.branchNumber = B.branchNumber AND
		B.branchName = 'Latveria'

/* Question 13*/
SELECT COUNT (DISTINCT firstName) AS distinct_firstNames, COUNT (sin) AS employee_count
FROM Employee E, Branch B
WHERE E.branchNumber = B.branchNumber AND
		B.branchName = 'London'

/* Question 14*/
SELECT B.branchName, MIN (E.salary) AS min_salary, MAX (E.salary) AS max_salary, AVG (E.salary) AS average_salary
FROM Branch B, Employee E
WHERE B.branchNumber = E.branchNumber
GROUP BY B.branchName
ORDER BY branchName

/* Question 15*/
SELECT C.customerID, C.firstName, C.lastName
FROM Customer C, Owns O
WHERE C.customerID = O.customerID
GROUP BY C.customerID, C.firstName, C.lastName
HAVING COUNT (O.customerID) >= 2 
ORDER BY C.customerID

/* Question 16*/
SELECT AVG (C1.income) AS average_income_of_customer_older_than_50, AVG (C2.income) AS average_income_of_customer_younger_than_50
FROM Customer C1, Customer C2
WHERE DATEADD(YEAR, +50, C1.birthDate) > CONVERT (date, GETDATE()) AND DATEADD(YEAR, +50, C2.birthDate) < CONVERT (date, GETDATE()) 

/* Question 17*/
SELECT C1.customerID, C1.lastName, C1.firstName, C1.income, AVG (A1.balance) AS average_balance
FROM Customer C1, Owns O1, Account A1
WHERE (C1.lastName LIKE 'Jo%s%' OR C1.firstName LIKE 'A%[AEIOU]_') AND C1.customerID = O1.customerID AND O1.customerID IN
		(SELECT O2.customerID
			FROM Owns O2
			GROUP BY O2.customerID
			HAVING COUNT (O2.customerID) >= 3) AND 
		O1.accNumber = A1.accNumber
GROUP BY C1.customerID, C1.lastName, C1.firstName, C1.income
ORDER BY C1.customerID

/* Question 18*/
SELECT A.accNumber, A.balance, SUM (T.amount) AS sum_transaction_amounts, (A.balance - SUM (T.amount)) AS balance_subtract_sum_transaction_amounts
FROM Account A, Transactions T, Branch B
WHERE A.accNumber = T.accNumber AND A.branchNumber = B.branchNumber AND B.branchName = 'New York'
GROUP BY A.accNumber, A.balance
HAVING COUNT (T.accNumber) >= 10
ORDER BY A.accNumber

/* Question 19*/
SELECT B.branchName, A.type, AVG (T.amount) AS average_transaction_amount
FROM Branch B, Account A, Transactions T
WHERE A.branchNumber = B.branchNumber AND T.accNumber = A.accNumber
GROUP BY B.branchName, A.type
HAVING COUNT (A.type) >= 50
ORDER BY B.branchName, A.type

/* Question 20
SELECT DISTINCT B1.branchName, A1.type, A1.accNumber, T1.transNumber, T1.amount
FROM Branch B1, Account A1, Transactions T1
WHERE EXISTS (SELECT A2.type, AVG (T2.amount) as type_average FROM Account A2, Transactions T2 WHERE EXISTS 
	(SELECT A3.accNumber, AVG (T3.amount) as account_average
		FROM Account A3, Transactions T3
		WHERE A3.accNumber = T3.accNumber
		GROUP BY A3.accNumber
		HAVING AVG(T2.amount) > 3* AVG(T3.amount) )
	GROUP BY A2.type)

ORDER BY B1.branchName, A1.type, A1.accNumber, T1.transNumber*/
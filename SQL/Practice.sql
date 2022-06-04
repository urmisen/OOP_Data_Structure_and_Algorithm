## Employee

INSERT INTO `employe` (`E_id`, `E_name`, `Dept`, `Salary`) VALUES ('1', 'AAA', 'HR', '10000'), ('2', 'BBB', 'MRKT', '20000'), ('3', 'CCC', 'HR', '30000'), ('4', 'DDD', 'MRKT', '40000'), ('5', 'EEE', 'IT', '45000');

## Project

INSERT INTO `project` (`E_id`, `P_id`, `P_name`, `Location`) VALUES ('1', 'P1', 'IOT', 'DHAKA'), ('5', 'P2', 'BIG DATA', 'SYLHET'), ('3', 'P3', 'RETAIL', 'RAJSHAHI'), ('4', 'P4', 'ANDROID', 'KHULNA');

==> Query to display maximum salary from Employe Table.

SELECT MAX(Salary) FROM `employe` WHERE 1

==> Query to display Employee name who is taking maximum salary.

SELECT E_name, MAX(Salary) FROM `employe` WHERE 1;

Or,

SELECT E_name from employe WHERE Salary 
= (SELECT MAX(Salary) FROM `employe` WHERE 1);

==> Query to display all the salaries excluding highest salary from Employe Table.

SELECT Salary from employe WHERE Salary 
<>  (SELECT MAX(Salary) FROM `employe` WHERE 1)

==> Query to display second highest salary from Employe Table.

SELECT Max(Salary) from employe WHERE Salary <>  (SELECT MAX(Salary) FROM `employe` WHERE 1)

==> Query to display Employee name who is taking second highest salary.

SELECT E_name from employe WHERE Salary 
= (SELECT Max(Salary) from employe WHERE Salary 
<>  (SELECT MAX(Salary) FROM `employe` WHERE 1))

==> Query to display all the dept names along with no of employees working in it.

SELECT dept,COUNT(*)
FROM employe GROUP BY dept

==> Query to display all the dept where no of employes are less than 2.

SELECT dept as total_emp
FROM employe GROUP BY dept having COUNT(*)<2

==> Query to display all employe names who are working in the dept where no of employes are less than 2.

SELECT E_name from employe 
where dept IN 
(SELECT dept as total_emp
FROM employe 
GROUP BY dept 
having COUNT(E_id)<2)

==> Query to display the name of the employes who are working in a project.

SELECT E_name from employe 
where E_id IN 
(SELECT E_id FROM project WHERE 1)

==> Query to display the details of the employes who are working in at least a project.

SELECT * from employe 
where EXISTS 
(SELECT * FROM project WHERE project.E_id = employe.E_id)

==> Query to display the name of the employes who are working in a project.

(using subquer) = bottom up

SELECT * from employe 
where E_id IN 
(SELECT E_id FROM project WHERE 1)

or,

(using correlated nested query) = top down approach

SELECT * from employe 
where EXISTS 
(SELECT * FROM project WHERE project.E_id=employe.E_id)

or,

(using joining) = cross product + condition

SELECT * from employe,project 
WHERE project.E_id=employe.E_id;


===> find the N'th highest salary.



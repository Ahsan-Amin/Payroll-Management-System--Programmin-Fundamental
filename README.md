# Payroll-Management-System-Programmin-Fundamental
Payroll Management System
A department is managing information of each teacher to calculate salary. In this context department is maintaining following information the file named: EmployeesManagementSystem.txt
1.	Employee ID
2.	Employee Name
3.	Designation
4.	Basic Salary
5.	Month
6.	Leaves
7.	Allowed Leaves	
8.	Per Leave Deduction Rate
9.	Salary
The sample data of ten employees is:
Employee ID	Employee Name	Designation	Basic Salary	Month	Leaves	Allowed Leaves	Per Leave Deduction Rate	Salary
E001	Usman Raza	Lecturer	70000	January	5	3	2000	66000
E002	Zeeshan Akram	Assistant Professor	100000	January	0	4	3000	100000
E003	Saima Ahmad	Associate Professor	150000	January	0	5	5000	150000
E004	Irfan Ahmad	Assistant Professor	100000	January	10	4	3000	82000
E005	Haider Khan	Assistant Professor	100000	January	15	4	3000	67000
E006	Saad Raza	Associate Professor	150000	January	2	5	5000	150000
E007	Saima Akram	Associate Professor	150000	January	5	5	5000	150000
E008	Bushra Zulfiqar	Professor	180000	January	0	6	6000	180000
E009	Ali Raza	Lecturer	70000	January	0	3	2000	70000
E010	Farah Huusain	Lecturer	70000	January	0	3	2000	70000

First four fields give basic information of an employee including Employee ID, Employee Name, Designation and Salary.  In the fifth field the month information is maintained for which department will process salary of each employee based on leaves. Each employee has allowed number of leaves. If the Leaves are more than allowed leaves then per leave deduction rate is applied and is deducted from the basic salary using following formula:
Salary= Basic salary-(Leaves-Allowed Leaves) x Per Leave Deduction Rate
You are required to development the salary management system.  User will be given following menu
1.	Enter 1 to enter information of employee to manage salary of specific month
2.	Enter 2 to Print Salary Slip
3.	Enter 3 to enter information of new employee
4.	Enter 4 to Quit

1.	If user enters 1, the user will be asked to enter the information of employees and populate the following fields: Employee ID, Employee Name, Designation, Basic Salary, Month, Leaves, Allowed Leaves, Per Leave Deduction Rate. System will calculate the salary using the formula discussed above. System will store this information in EmployeesManagementSystem.txt. System will get information of all employees in loop and will exit the loop when user enters -1. 
2.	IF user enters 2, System will ask user to enter Month against which each employee salary slip will be printed. For example user enters “January”. System will process EmployeesManagementSystem.txt file and generate salary slips of each employee individually. These salary slips will be saved on disk having file naming convention as <Employee ID>_<EmployeeName>_<Month>_SalarySlip.txt.  The information in each slip is saved in defined format as discussed in the table below. Please note that text of <Employee ID>_<EmployeeName>_<Month>  will be extracted from EmployeesManagementSystem.txt against each employee. For Example in main menu user enters 2
Please Enter Month: January
System will process salary of each employee and generate the slips as

Salary Month: January
Employee Name: Saima Ahmad
Designation: Associate Professor
Salary: 66000	Salary Month: January
Employee Name:  Haider Khan
Designation: Assistant Professor
Salary: 67000
E003_ Saima Ahmad_January_SalarySlip.txt	E005_ Haider Khan _January_SalarySlip.txt


5.	IF user Enter 3, System will ask information of employee including Employee ID, Employee Name, Designation, Basic Salary, Month, Leaves, Allowed Leaves and Per Leave Deduction Rate,  and will populate in EmployeesManagementSystem.txt.  
Deadline of the project is : February , 23 2022.
The implemented project will be evaluated based on the following criteria
1.	Define and usage of structure
2.	Define and usage of functions
3.	Reading the writing file using structures
4.	Implementation of formula
5.	Salary slips files naming conventions
6.	Overall complete management of system

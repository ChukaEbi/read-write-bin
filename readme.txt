Name: Chuka Ebi
Username: cebi

List of files:
Doxyfile //Used to generate HTML files.
makefile //The file translate the program from human-readable form into a form				which can be executed by the computer.
etest.h //Contains the function prototypes for all the source files.
etest.c // code for Part 1 and 2
func.c // code for Part 1 and 2
p4.c // code for Part 3, 4 and 5
p4.h
binwrite.c // code for Part 6
binread.c // code for Part 7

Description:
etest.c, func.c: : Include function which accepts as parameters all the data needed for an Employee2 struct and functions for printing and outputting an Employee2 struct. Include a function to prompts the user to enter an employee's name and salary, then allocates an Employee2 structure and puts data into it.
	All those new functions are demonstrated in main().

p4.c: Program to ask user to input number of employees and employees' data, store them in Employee2 struct, and print all employees' data out to a text file. Program to read employee's data from a text file, store them, and print them out.

binwrite.c: 
	Binary file version of function(part 3,4) for writing text file
binread.c: 
	Binary file version of function(part 5) for reading text file


Instruction for running the code:
Remarks:
Part 3,4,5. I put it together. It will read and print from part automatically without 		need of other command
After all command typed, there will be â¤½etest.txtâ¤, â¤½part4.txtâ¤, â¤½part6.binâ¤ generated.

In terminal
1. make
2. type â¤½./etestâ¤ to achieve part 1 & 2
3	Starting program etest.
	Please enter employee's name: abc
	Please enter salary: 123
	The salary abc 's is: 123
	About to write to file etest.txt.
	Employee:. Name = Harry Palmer, Salary = 50000
	Employee:. Name = Erik Grantby, Salary = 60000
	Employee:. Name = Bill, Salary = 100000
	Employee2:. Name = Ceaser, Salary = 20000
	Employee2:. Name = David, Salary = 20000
	Employee2:. Name = abc, Salary = 123
	Ending program etest.
4. type â¤½./p4â¤ to achieve part 3, 4 &5
5. result
	please enter the number of employees
	3
	Please enter employee's name: aaa 
	Please enter salary: 11111111
	The salary aaa 's is: 11111111
	Please enter employee's name: bbb
	Please enter salary: 22222222
	The salary bbb 's is: 22222222
	Please enter employee's name: ccc
	Please enter salary: 33333333
	The salary ccc 's is: 33333333	
	/*part 5, read employee from text file*/
	Employee2:. Name = aaa, Salary = 11111111
	Employee2:. Name = bbb, Salary = 22222222
	Employee2:. Name = ccc, Salary = 33333333
6. type â¤½./binwriteâ¤ to achieve part 6
7. result: ./binwrite
	please enter the number of employees
	2
	Please enter employee's name: apple
	Please enter salary: 555555
	The salary apple 's is: 555555
	Please enter employee's name: beer
	Please enter salary: 666666
	The salary beer 's is: 666666
8. type â¤½./binreadâ¤ to achieve part 7
9. result: CEBI27:assig5 MMXX$ ./binread
	File opened successfully

#include <stdlib.h>
#include "etest.h"
#include <errno.h>
#include "p4.h"
#include <stdio.h>
#define MAX_EMPLOYEE 40

/** Program to enter number of employees' data and demonstrate writing to text files
 * @author Chuka Ebi
 */


int main() {

	// user input
	printf("please enter the number of employees\n");
	int numbers;
	scanf("%d", &numbers);
	int i;
	// construct array of employee2
	Employee2* emps = (Employee2 *)malloc(sizeof(Employee2) * numbers);
	for (i = 0; i < numbers; i ++) {
		emps[i] = *inputEmployee2();
	}
        FILE* file = fopen("part4.txt","w");
	for (i = 0; i < numbers; i ++) {
		outputToText(file, emps[i]);
	}
	// close textfile
	fclose(file);
	free(emps);

	// demonstrating reading functionality
	FILE* fileinput = fopen("part4.txt", "r");
	readFromFileAndPrint(fileinput);
	fclose(fileinput);
	return 0;
}
// helper function for writing a employee2 to file
void outputToText(FILE* file, Employee2 e) {
	fprintf(file, "%s\n%d\n", e.name, e.salary);
}

// read a file and print the content
void readFromFileAndPrint(FILE* file) {
	int i = 0;

	// allocate array
	Employee2* emps = (Employee2*)malloc(sizeof(Employee2) * MAX_EMPLOYEE);
	while ((!feof(file)) && i < MAX_EMPLOYEE) {
		char* name = (char*)malloc(sizeof(char) * MAX_EMPLOYEE);
		int salary;
		fscanf(file, "%s\n %d", name, &salary);
		// construct employee2
                Employee2* e;
		emps[i] = *fillinEmployee2(e,salary, name);

		i ++;
	}
	if (i == MAX_EMPLOYEE) {
		fprintf(stderr, "too many employee input\n");
	}
	int j;
	// print employee2
	for (j = 0; j < i - 1; j ++) {
		printEmployee2(&emps[j]);
	}
	free(emps);
}

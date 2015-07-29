#include <stdlib.h>
#include "etest.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

/** Program to demonstrate writing to binary files
 * @author Chuka Ebi
 */
Employee2* inputEmployee2();

int main() {

    // user input
	printf("please enter the number of employees\n");
	int numbers;
	scanf("%d", &numbers);
	int i;

    // allocate memory
	Employee2* emps = (Employee2 *)malloc(sizeof(Employee2) * numbers);
	for (i = 0; i < numbers; i ++) {
		emps[i] = *inputEmployee2();
	}
    //open binary file to write
	int fd = open("part6.bin", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd < 0) {
		printf("Unable to open file. Error %d: %s\n", errno, strerror(errno));
	}
    // write to file
	for (i = 0; i < numbers; i ++) {
		ssize_t count = write(fd, &emps[i], sizeof(Employee2));
	}
    // close file
	close(fd);
	free(emps);
	return 0;
}

#if 0
// helper function to prompt user to 
// enter the information for Employee struct
// and then construct thus struct as return value
Employee2* inputEmployee2(){
    char * name;
    name = (char *)malloc(sizeof(char) * MAX_NAME);
    printf("Please enter employee's name: ");
    scanf("%s", name);
    
    int salary;
    char *inputline; // pointer to input line
    int nc; // Number of conversions successfully completed
    int goodinput = 0; // Flag: 0 = false = Input not yet good
    

    // prompt for user input
    while (!goodinput) {
        inputline = readline("Please enter salary: "); // Read the input line
        
        nc = sscanf(inputline, "%d",&salary); // Try to convert
        
        if (nc > 0 && salary > 0) {
            printf("The salary %s 's is: %d\n", name, salary);
            goodinput = 1; // Break out if successful
        } else {
            printf("Try again\n");
        }
        
        
    }
    // construct struct
    Employee2* J;
    Employee2* Jemployee;
    Jemployee = fillinEmployee2(J, salary, name);
    free(name);
    return Jemployee;
}
#endif



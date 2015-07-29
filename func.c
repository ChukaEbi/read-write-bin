#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "etest.h"
#include <readline/readline.h>
#include <readline/history.h>



/** Outputs one Employee structure in verbose form, to an open file stream
 * @param stream The output stream to write to (must already be open).
 * @param employee Pointer to the structure to print
*/

void outputEmployeeVerbose(FILE *stream, Employee *employee) {
  fprintf(stream, "Employee:. Name = %s, Salary = %d\n",
	  employee->name, employee->salary);
}

/** Prints one Employee structure in verbose form
 * @param employee Pointer to the structure to print
*/

void printEmployeeVerbose(Employee *employee) {
 // Save effort -- make use of other function already written!
  outputEmployeeVerbose(stdout, employee);
}

/** Fills in the fields of an Employee structure
 * @param emp Pointer to the struct. MUST ALREADY EXIST!
 * @param salary Annual salary in dollars
 * @param name Character string holding the name. Gets copied into struct.
 * @return Pointer to the same struct
 */
Employee* fillinEmployee(Employee* emp, int salary, char* name) {
  emp->salary = salary;
  strncpy(emp->name, name, MAX_NAME);
  return emp;

}

/** Allocates an Employee struct and fills in its fields. 
 * @param salary Annual salary in dollars
 * @param name Character string holding the name. Gets copied into struct.
 * @return Pointer to the newly-allocated struct.
 */
Employee* createEmployee(int salary, char* name) {
   Employee* eptr;
   eptr = (Employee*) malloc(sizeof(Employee));
   fillinEmployee(eptr, salary, name);
   return eptr;
}
/**Fills in the fields of an Employee2 structure
*@param emp Pointer to the Employee2 struct.
*@param salary Annual salary in dollars
*@param name pointer to the C-style string 
*@return Pointer to the same struct
*/
Employee2* fillinEmployee2(Employee2* emp, int salary, char* name){
   emp->salary = salary;
   char* nptr;
   emp->name = strdup(name);
   //strcpy(emp->name,*nptr);
   return emp;
}

Employee2* createEmployee2(int salary, char* name){
    Employee2* mem = (Employee2*) malloc(sizeof(Employee2));
    mem -> salary = salary;
    char* name2 = (char*)malloc(sizeof(char));
    name2 = strdup(name);
    mem -> name = name2;
    return mem;
}


/**Outputs one Employee2 structure in verbose form, to an open file stream
*@param stream The output stream to write to(must be already open)
*@param employee Pointer to the Employee2 to print
*/
void outputEmployee2(FILE *stream, Employee2 *employee){
  fprintf(stream,"Employee:. Name = %s, Salary = %d\n",
           employee->name, employee->salary);
}

/**Prints one Employee2 structure in vrbose form
*@param employee Pointer to the Employee2 struct to print
*/
void printEmployee2(Employee2* employee){
  outputEmployee2(stdout, employee);
}
/**prompt user for information for an Employee2 struct
*@return pointer to the filled in Employee2 struct
*/
Employee2* inputEmployee2(){
  char* name;
  name = (char*)malloc(sizeof(char) *40);
  name = readline("Please enter employee's name: "); 
  int salary;
  char *inputline; // pointer to input line
  int nc; // Number of conversions successfully completed
  int goodinput = 0; // Flag: 0 = false = Input not yet good
 
  while (!goodinput) {
        inputline =readline("Please enter salary: "); // Read the input line
        nc = sscanf(inputline, "%d",&salary); // Try to convert
        if (nc > 0 && salary > 0) {
            printf("The salary for  %s is: %d\n", name, salary);
            goodinput = 1; // Break out if successful
        } else {
            printf("Try again\n");
        }
  }
  // construct employee2 struct
    Employee2* enteremployee;
    Employee2* emp;
    enteremployee = fillinEmployee2(emp,salary, name);
    free(name);
    return enteremployee;
}

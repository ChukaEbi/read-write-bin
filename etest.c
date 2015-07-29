#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "etest.h"
#include <readline/readline.h>
#include <readline/history.h>

#define OUTFILENAME "etest.txt"
#define MAX_NAME (40)

int main() {
  printf("Starting program etest.\n"); 

  // Anybody recognize these names?
  Employee harry; // Declare a local variable (a struct).
  harry.salary = 50000;
  strcpy(harry.name, "Harry Palmer"); // Copy into array in struct

  Employee bluejay; // Declare a local variable (a struct).
  bluejay.salary = 60000;
  strcpy(bluejay.name, "Erik Grantby"); // Copy into array in struct

  Employee yellowtiger;
  fillinEmployee(&yellowtiger, 500000, "Jon Snow");

  Employee* rubyhawk;
  rubyhawk = createEmployee(1000, "Tony Staark");

  Employee2 crimsoneagle;
  fillinEmployee2(&crimsoneagle, 10000, "Eddard Hazy");

  Employee2 emeraldshark;
  fillinEmployee2(&emeraldshark,2000, "Blaise Matuidi");
  
  Employee2* golddragon;
  golddragon = inputEmployee2();

  // Output the employees to a file.
  printf("About to write to file %s.\n", OUTFILENAME);
  FILE *outfile = fopen(OUTFILENAME, "w"); // Open or create file for writing
  if(outfile == NULL){
       fprintf(stderr, " %d Error: %s to write to etest\n", errno,  strerror(errno));
	printf("Try again\n");
	return 1;
}
  outputEmployeeVerbose(outfile, &harry);
  outputEmployeeVerbose(outfile, &bluejay);
  outputEmployeeVerbose(outfile, &yellowtiger);
  outputEmployeeVerbose(outfile, rubyhawk);

  outputEmployee2(outfile, &crimsoneagle);
  outputEmployee2(outfile, &emeraldshark);
  outputEmployee2(outfile, golddragon);
  
  fclose(outfile); // Close the file

  // Output the employees to stdout.
  printEmployeeVerbose(&harry);
  printEmployeeVerbose(&bluejay);
  printEmployeeVerbose(&yellowtiger);
  printEmployeeVerbose(rubyhawk);

  printEmployee2(&crimsoneagle);
  printEmployee2(&emeraldshark);
  printEmployee2(golddragon);
  printf("Ending program etest.\n"); 
  return 0;
}

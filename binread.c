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
/** Program to demonstrate reading to binary files
 * @author Chuka Ebi
 */

int main() {
  //open the binary file
	int fd = open("part6.bin", O_RDONLY);
	if (fd >= 0) {
    printf("File opened successfully\n");
  } 
  // variable used as flag to indicate if the process of reading has finished
  int readable = 1;
  while (readable) {
  	Employee2 emp;
  	ssize_t count = read(fd, &emp, sizeof(Employee2));

    // stop while loop if nothing more to read
  	if (count <= 0) {
  		readable = 0;
  	} else {
  		printf("Employee name: %s salary: %d\n", emp.name, &emp.salary);
  	}

  }
  // close the binary file
  close(fd);
	return 0;
}

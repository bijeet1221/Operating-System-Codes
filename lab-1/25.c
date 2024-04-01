// Program no: 25
// Name : Bijeet Basak(IMT2022510)
// a. Execute a program using the exec system call.
// b. Pass input to an executable program (e.g., execute an executable as $./a.out name).

#include <stdio.h>
#include<unistd.h> // allows to use execv()
#include<fcntl.h> // provides functions and constants to work with file descriptors 

int main(int argc, char *argv[])
{
	printf("file_25...\n");
	execv("./helloWorld", argv);
}
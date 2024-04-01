// Program no: 23
// Name : Bijeet Basak(IMT2022510)
// Write a program to create an orphan process.

#include <stdio.h>
#include <unistd.h> // allows to use fork()
#include <fcntl.h>  // provides functions and constants to work with file descriptors 
#include <stdlib.h>

int main()
{
	int x=fork();
	if(x==0)
    {
		printf("In child process...\n");
		printf("PID: %d\nPPID: %d\n", getpid(), getppid());
		sleep(10);

		printf("PID: %d\nPPID: %d\n", getpid(), getppid());
		printf("Still in child process...\n");
        sleep(5);

        printf("PID: %d\nPPID: %d\n", getpid(), getppid());
		printf("Still in child process...\n");
	}
	else
    {
		printf("Original PPID: %d\n", getpid());
		printf("In parent process...\n");
		exit(0);
	}
}
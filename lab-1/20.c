// Program no: 20
// Name : Bijeet Basak(IMT2022510)
// Write a program that calls fork and prints both the
// parent and child process IDs.

#include <stdio.h>
#include <unistd.h>

int main()
{
	int x = fork();
	if(x==0)
		printf("Child pid: %d\n", getpid());
	else	
		printf("Parent pid: %d\n", getpid());
	return 0;
}
// Program no: 22
// Name : Bijeet Basak(IMT2022510)
// Write a program to create a Zombie state of the running program.

#include <stdio.h>
#include <unistd.h> //allows to use sleep()
#include <stdlib.h>

int main()
{
	int x=fork();
	if(x==0)
    {
		printf("Child: %d\n", getpid());
		sleep(25);
	}
	else
    {
		printf("Parent: %d\n", getpid());
		exit(0);
	}
}
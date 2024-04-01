// Program no: 3
// Name : Bijeet Basak(IMT2022510)
// Write a program that creates a file and prints its file
// descriptor value using the creat() system call.

#include <stdio.h>
#include <fcntl.h> //provides functions and constants to work with file descriptors
#include <unistd.h> // allows to use creat()

int main()
{
	char *file="3_file.txt";
	int x=creat(file,0666); // specifies read and write permissions for all users.
	printf("fd: %d\n",x);
}

// Program no: 4
// Name : Bijeet Basak(IMT2022510)
// Write a program to open an existing file in read-write mode.
// Experiment with the O_EXCL flag.

#include <stdio.h>
#include <fcntl.h> //provides functions and constants to work with file descriptors
#include <unistd.h> // alolows to use open()

int main()
{
	char *file="4_file.txt";
	int x=open(file, O_RDWR | O_EXCL);
	printf("fd = %d\n",x);
}

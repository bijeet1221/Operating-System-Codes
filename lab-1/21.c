// Program no: 21
// Name : Bijeet Basak(IMT2022510)
// Develop a program that opens a file, calls fork,
// and allows both the child and parent processes to write to the file. Examine the output of
// the file.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // provides functions and constants to work with file descriptors 

int main()
{
	int fd=open("test_21.txt", O_RDWR);
	int x = fork();
	if(x==0)
    {
		printf("Child....\n");
		write(fd, "Child is writing\n", 16);
	}
	else
    {
		printf("Parent....\n");
		write(fd, "Parent is writing\n", 17);
	}
	return 0;
}
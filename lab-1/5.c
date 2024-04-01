// Program no: 5
// Name : Bijeet Basak(IMT2022510)
// Create a program that generates five new files in an infinite loop.
// Execute the program in the background and inspect the file descriptor table at /proc/pid/fd.

#include <stdio.h>
#include <fcntl.h>  //provides functions and constants to work with file descriptors
#include <unistd.h> // allows to use creat()

int main()
{
	int x1=creat("xyz1",0777); // grants full read, write, and execute permissions
	int x2=creat("xyz2",0777);
	int x3=creat("xyz3",0777);
	int x4=creat("xyz4",0777);
	int x5=creat("xyz5",0777);
	printf("fd 1 : %d\n",x1);
	printf("fd 2 : %d\n",x2);
	printf("fd 3 : %d\n",x3);
	printf("fd 4 : %d\n",x4);
	printf("fd 5 : %d\n",x5);
	while(1) // infinte loop
	{};
	return 0;
}







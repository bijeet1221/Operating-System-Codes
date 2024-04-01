// Program no: 6
// Name : Bijeet Basak(IMT2022510)
// Craft a program to take input from STDIN and display
// it on STDOUT using only read/write system calls.

#include <stdio.h>
#include <unistd.h> // allows to use read()

int main()
{
   char a[256];
   read(0,a,256);
   int count=0;
   for(int i = 0; i < 1000; i++)
   {
		if(a[i] == '\n'){
			break;
		}
		else
			count++;
	}
	write(1, a, count);
	return(0);
}
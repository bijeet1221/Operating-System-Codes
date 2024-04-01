// Program no: 1
// Name : Bijeet Basak(IMT2022510)
// Utilize both shell commands and system calls to create the
// following types of files:
// c. FIFO (using either the mkfifo Library Function or the mknod system call)

#include <stdio.h>
#include <sys/stat.h>  //Functions and data structures used to retrieve information about files
#include <fcntl.h>   //provides functions and constants to work with file descriptors

int main()
{
	printf("Enter fifo file name: ");
    char a[256];
    scanf("%s",a);
    if(mkfifo(a,0666) == 0) // specifies read and write permissions for all users.
        printf("fifo file created successfully.\n");
    else 
        printf("Error\n");
    return 0;
}


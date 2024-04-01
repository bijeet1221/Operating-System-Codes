// Program no: 12
// Name : Bijeet Basak(IMT2022510)
// Create a program to find out the opening mode of a
// file using the fcntl system call.

#include <stdio.h>
#include <unistd.h> // allows to use open()
#include <fcntl.h> // provides functions and constants to work with file descriptors 

int main()
{
    char file[1000];
    printf("Enter filename");
    scanf("%s",file);
    int fd=open(file,O_RDWR);
    int x=fcntl(fd,F_GETFL);
    close(fd);
    if(x==32768)
        printf("O_RDONLY\n");
    else if(x==32769)
        printf("O_WRONLY\n");
    else if(x==32770)
        printf("O_RDWR\n");
    else if(x==32793)
        printf("O_WRONLY | O_APPEND\n");
    else if(x==32794)
        printf("O_RDWR | O_APPEND\n");
    else
        printf("Something else\n");
}
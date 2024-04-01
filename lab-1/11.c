// Program no: 11
// Name : Bijeet Basak(IMT2022510)
// File Descriptor Duplication and Appending: Write a program to open a file, duplicate the
// file descriptor, append the file with both descriptors, and verify whether the file is updated
// correctly.
// a. Use dup
// b. Use dup2
// c. Use fcntl

#include <stdio.h>
#include <unistd.h> //allows to use dup(),open()
#include <fcntl.h> // provides functions and constants to work with file descriptors 

int main()
{
    char temp[1000];
    int fd1=open("11_file.txt",O_WRONLY | O_APPEND);
    int fd2=dup(fd1);
    write(fd1,"Hello\n",6);
    write(fd2,"Hello World\n",12);
    dup2(fd1,4);
    write(4,"Have fun world\n",15);
    int fd3=fcntl(fd1,F_DUPFD,0);
    write(fd3,"EXITT\n",6);
    close(fd1);
    close(fd2);
    close(fd3);
}
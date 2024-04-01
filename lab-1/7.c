// Program no: 7
// Name : Bijeet Basak(IMT2022510)
// Develop a program to copy the contents of file1 into file2, emulating the
// behavior of the $cp file1 file2 command.

#include <unistd.h> // allows to use open()
#include <stdio.h>
#include <string.h>
#include <fcntl.h>  //provides functions and constants to work with file descriptors

int main()
{
    char f1[1000],f2[1000],temp[1000];
    for(int i=0;i<1000;i++)
    {
        strcpy(&temp[i],"");
    }
    printf("Enter file names");
    scanf("%s %s",f1,f2);
    int fd1=open(f1,O_RDONLY); // Read Only flag
    int x=read(fd1,temp,sizeof(temp));
    int fd2=open(f2,O_WRONLY);
    int y=write(fd2,temp,sizeof(temp));
    close(fd1);
    close(fd2);
}
// Program no: 14
// Name : Bijeet Basak(IMT2022510)
// Write a program that takes input from the command line and
// identifies the type of file. Ensure the program can recognize various file types.

#include <stdio.h>
#include <sys/stat.h> // allows to use stat structure
#include <sys/types.h> // allows to make system calls
#include <unistd.h> // access for handling stat

int main(int argc,char *argv[])
{
    struct stat st;
    stat(argv[1],&st);
    switch(st.st_mode & __S_IFMT)
    {
        case __S_IFBLK:
            printf("block device\n");
            break;
        case __S_IFCHR:
            printf("character device\n");
            break;
        case __S_IFDIR:
            printf("directory\n");
            break;
        case __S_IFIFO:
            printf("FIFO/pipe\n");
            break;
        case __S_IFLNK:
            printf("symlink\n");
            break;
        case __S_IFREG:
            printf("regular file\n");
            break;    
        case __S_IFSOCK:
            printf("socket\n");
            break;
        default:
            printf("unknown\n");
    }
}
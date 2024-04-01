// Program no: 16
// Name : Bijeet Basak(IMT2022510)
// Write a program to perform mandatory locking with
// the following implementations:
// a. Implement a write lock.
// b. Implement a read lock.


#include <stdio.h>
#include <unistd.h> // allows to use open()
#include <fcntl.h>  // provides functions and constants to work with file descriptors 

int main()
{
    int fd = open("16_file.txt",O_WRONLY);
    
    // Define a file lock structure
    struct flock wrlk;
    wrlk.l_type=F_WRLCK; // set the lock type to write lock
    wrlk.l_whence=SEEK_SET; // set the starting offset of the lock to beginning of file
    wrlk.l_start=0; // starting offset=0
    wrlk.l_len=0;  // set length of lock to zero
    wrlk.l_pid=getpid(); // set process ID of locking process
    
    // set a write lock on file
    int status = fcntl(fd,F_SETLKW,&wrlk);
    if(status==-1)
        printf("could not lock the file\n");
    else
        printf("Write Lock implemented\n");
    
    // Unlocking the file
    wrlk.l_type=F_UNLCK;
    status = fcntl(fd,F_SETLKW,&wrlk);
    if(status==-1)
        printf("The file could not be unlocked\n");
    else
    printf("The file is now unlocked\n");
    close(fd);
}
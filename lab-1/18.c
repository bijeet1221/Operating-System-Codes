// Program no: 18
// Name : Bijeet Basak(IMT2022510)
// Write a program to perform record locking with the
// following implementations:
// a. Implement a write lock.
// b. Implement a read lock.
// Create three records in a file. Whenever you access a particular record, first lock it, then
// modify/access it to avoid race conditions.. Open the file with od command and examine the empty spaces between the data.


#include <stdio.h>
#include <unistd.h> // allows to use open()
#include <sys/types.h> // contains various data types used in system calls such as pid_t for process IDs.
#include <sys/stat.h> // allows to define struct stat
#include <fcntl.h> // provides functions and constants to work with file descriptors

int main()
{
    int arr[] = {0, 0, 0};
    int fd = open("18_file.txt", O_RDWR | O_CREAT);
    write(fd, arr, sizeof(arr));
    close(fd);
}
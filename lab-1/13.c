// Program no: 13
// Name : Bijeet Basak(IMT2022510)
// Develop a program to wait for input from STDIN for 10
// seconds using select. Include proper print statements to verify data availability within the
// specified time

#include<stdio.h>
#include<fcntl.h>  // provides functions and constants to work with file descriptors 
#include<sys/select.h> // allows to use select(),which allows monitoring multiple file descriptors to see if I/O is possible on any of them.

int main()
{
    fd_set fds;
    struct timeval t_val;
    int retval;
    t_val.tv_sec = 5;
    t_val.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    retval = select(1 ,&fds, NULL, NULL, &t_val);
    if (retval == -1)
        printf("Error\n");
    else if(retval)
        printf("Data is available now.\n");
    else
        printf("No data available in five seconds.\n");
}
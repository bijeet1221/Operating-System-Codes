# include <stdio.h>
#include <fcntl.h> // provides functions and constants to work with file descriptors 
#include <unistd.h> // allows to use open()
# include <sys/stat.h>

int main(int argc,char*argv[])
{
    int n=1;
    scanf("%d", &n);

    int fd = open("tickets.txt", O_WRONLY | O_CREAT, 0744);
    write(fd, &n, sizeof(int));
    printf("Write successsful\n");

    close(fd);
    return 0;
}
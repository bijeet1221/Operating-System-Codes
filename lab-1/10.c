// Program no: 10
// Name : Bijeet Basak(IMT2022510)
// Implement a program to open a file in read-write mode, write 10
// bytes, move the file pointer by 10 bytes using lseek, and then write another 10 bytes.
// a. Check the return value of lseek.
// b. Open the file with od command and examine the empty spaces between the data.


#include <stdio.h>
#include <unistd.h> // allows to use open()
#include <fcntl.h>  // provides functions and constants to work with file descriptors

int main()
{
	int fd = open("10_file.txt", O_CREAT | O_RDWR | O_EXCL);
	
    if (fd == -1)
        printf("File already exists.\n");
    
    char t[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	write(fd, t, 10);
	int ret_l = lseek(fd, 10, SEEK_CUR);
	write(fd, t, 10);

	printf("%d\n", ret_l);

    close(fd);
}
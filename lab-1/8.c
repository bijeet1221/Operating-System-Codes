// Program no: 8
// Name : Bijeet Basak(IMT2022510)
// Write a program to open a file in read-only mode, read line by line,
// and display each line as it is read. Close the file upon reaching the end of the file.

#include <stdio.h>
#include <fcntl.h>  // provides functions and constants to work with file descriptors
#include <unistd.h> // allows to use open()

int main(){
	int fd = open("8_file.txt", O_RDONLY);
	lseek(fd, 0, SEEK_SET);
	char t[1];
	t[0] = '1';
	while(&t[0] != NULL){
		read(fd, t, 1);
		if(t[0] == '\n'){
			getchar();
		}
		write(1, t, 1);
	}
    close(fd); // closing file
}
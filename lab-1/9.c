// Program no: 9
// Name : Bijeet Basak(IMT2022510)
// Create a program to print various details about a given file,
// including:
// a. Inode
// b. Number of hard links
// c. UID
// d. GID
// e. Size
// f. Block size
// g. Number of blocks
// h. Time of last accessi. Time of last modification
// j. Time of last change

#include <stdio.h>
#include <sys/types.h> //  for stat() system call
#include <sys/stat.h>  // allows to use stat structure
#include <unistd.h>  // allows to use open()
#include <fcntl.h>  // provides functions and constants to work with file descriptors
#include <time.h>   // provides functions to work with time


int main()
{
	struct stat status;
    int fd = open("9_file.txt", O_RDONLY);
    int stats = lstat("first.txt", &status);
    printf("File inode:   %ju\n", status.st_ino);
    printf("Number of Links: %ju\n", status.st_nlink);
    printf("UID:   %ju\n", (u_int64_t) status.st_uid);
    printf("GID: %ju\n", (u_int64_t) status.st_gid);
    printf("File Size:   %jd bytes\n", status.st_size);
    printf("Block Size:   %jd\n", status.st_blksize);
    printf("Number of Blocks:   %jd\n", status.st_blocks);
    printf("Time of Last Access:   %s\n", ctime(&status.st_atime));
    printf("Time of Last Modification:   %s\n", ctime(&status.st_mtime));
    printf("Time of Last Change:   %s\n", ctime(&status.st_ctime));
	close(fd);
	return 0;
}
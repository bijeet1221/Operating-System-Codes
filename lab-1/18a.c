// Program no: 18
// Name : Bijeet Basak(IMT2022510)
// Write a program to perform record locking with the
// following implementations:
// a. Implement a write lock.
// b. Implement a read lock.
// Create three records in a file. Whenever you access a particular record, first lock it, then
// modify/access it to avoid race conditions.. Open the file with od command and examine the empty spaces between the data.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // provides functions and constants to work with file descriptors
#include <sys/types.h> // contains various data types used in system calls such as pid_t for process IDs.
#include <unistd.h> // allows to use open()

int main()
{
    // Open the file "18.txt" in read/write mode
    int fd = open("18_file.txt", O_RDWR);

    // Ask user to choose a record to lock
    int input;
    printf("Choose a record: 1 or 2 or 3 :");
    scanf("%d", &input);

    // Define a file lock structure
    struct flock t;
    t.l_type = F_WRLCK;  // Set the lock type to write lock
    t.l_whence = SEEK_SET;  // Set the starting offset of the lock to the beginning of the file
    t.l_start = (input - 1) * sizeof(int); // Lock the specific record by calculating the offset
    t.l_len = sizeof(int);  // Set the length of the lock to the size of an integer
    t.l_pid = getpid();  // Set the process ID of the locking process

    // Set a write lock on the chosen record
    printf("Write lock has been set\n");
    fcntl(fd, F_SETLKW, &t);

    // Read the value of the chosen record
    int record_val = 0;
    lseek(fd, (input - 1) * sizeof(int), SEEK_SET);  // Move the file pointer to the chosen record
    read(fd, &record_val, sizeof(int));  // Read the value of the record
    record_val++;  // Increment the value of the record

    // Print the updated value of the record
    printf("The value of the record now is: %d\n", record_val);

    // Write the updated value back to the file
    lseek(fd, (input - 1) * sizeof(int), SEEK_SET);  // Move the file pointer back to the record
    write(fd, &record_val, sizeof(int));  // Write the updated value to the record

    // Wait for user input to unlock the record
    printf("Enter to unlock");
    getchar();

    // Unlock the record
    t.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &t);
    printf("Record has been unlocked\n");

    // Close the file descriptor
    close(fd);

    return 0;
}

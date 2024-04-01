// Program no: 17
// Name : Bijeet Basak(IMT2022510)
// Develop a program to simulate online ticket
// reservation with the implementation of a write lock. Write one program to open a file, store
// a ticket number, and exit. Write a separate program to open the file, implement a write
// lock, read the ticket number, increment the number, print the new ticket number, and then
// close the file. Implement a read lock.


#include <stdio.h>
#include <fcntl.h> // provides functions and constants to work with file descriptors 
#include <unistd.h> // allows to use open(),read(),write( ),close() 
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int fd;
    // Display a message before attempting to lock the file
    write(1, "Before lock\n", sizeof("Before lock\n"));
    // Open the file "tickets.txt" for reading and writing
    fd = open("tickets.txt", O_RDWR);

    // Initialize a file lock structure
    struct flock lock;
    lock.l_whence = SEEK_SET; // Set the starting offset for the lock
    lock.l_len = 0; // Lock the entire file
    lock.l_start = 0; // Start locking from the beginning of the file
    lock.l_type = F_WRLCK; // Set a write lock

    // Apply the lock to the file
    fcntl(fd, F_SETLKW, &lock);

    int num;
    // Read the current number of tickets from the file
    lseek(fd, 0, SEEK_SET);
    read(fd, &num, sizeof(int));

    // Display the current number of tickets
    printf("Number of tickets: %d\n", num);
    printf("Incrementing\n");
    num += 1; // Increment the number of tickets

    // Write the updated number of tickets back to the file
    lseek(fd, 0, SEEK_SET);
    write(fd, &num, sizeof(int));

    char ch;
    // Wait for user input to continue
    read(0, &ch, sizeof(char));
    // Display a message after incrementing and before unlocking
    write(1, "Incremented. Now unlocking\n", sizeof("Incremented. Now unlocking\n"));

    // Unlock the file
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("Unlocked\n");

    // Close the file
    close(fd);
}

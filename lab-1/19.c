// Program no: 19
// Name : Bijeet Basak(IMT2022510)
// Develop a program to initiate a process in distinct states:
// a. running
// b. sleeping
// c. stopped
// Confirm the current state of the process using the relevant commands.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // allows to use getpid()
#include <sys/wait.h> // allows to use wait

int main()
{
    int x = fork();  // Fork a child process
    int wstat;
    if (x< 0) 
        printf("Fork failed\n");

    else if (x == 0) {
        // Child process
        printf("Child process: PID=%d\n", getpid());

        // Perform some work
        printf("Child process is running...\n");
        sleep(5); // Sleep for 5 seconds
        printf("Child process is stopping...\n");
        // Exit
        exit(0);
    } 
    else 
    {
        // Parent process
        printf("Parent process: PID=%d, Child PID=%d\n", getpid(), x);

        // Wait for the child to complete
        int status;
        x=wait(&wstat);
        if (WIFEXITED(wstat)) 
            printf("Child process exited normally with status %d\n", WEXITSTATUS(wstat));
        else 
            printf("Child process exited abnormally\n");
    }
}

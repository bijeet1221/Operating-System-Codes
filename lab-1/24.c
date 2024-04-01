// Program no: 24
// Name : Bijeet Basak(IMT2022510)
// Write a program to create three child processes.
// The parent process should wait for a specific child process using the waitpid system call.

#include<stdio.h>
#include<unistd.h> // allows to use fork()
#include<fcntl.h> // provides functions and constants to work with file descriptors 
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    int i, stat;
    pid_t pid[3];
    for (i = 0; i < 3; i++)
    {
        pid[i] = fork();
        if (pid[i] == 0)
        {
            printf("child %d, %d\n", i, getpid());
            if(i == 1)
                sleep(5);
            else
                sleep(2);
            exit(100 + i);
        }
    }
    pid_t cpid_to_wait = waitpid(pid[1], &stat, 0);
    printf("Child %d terminated with status: %d\n", cpid_to_wait, WEXITSTATUS(stat));
}
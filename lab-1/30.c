// Program no: 30
// Name : Bijeet Basak(IMT2022510)
// Create a program to execute a
// task at a specific time using a Daemon process

# include <stdio.h>
# include <unistd.h> // allows to use fork()
# include <sys/stat.h> // allows to 
# include <stdlib.h>

int main()
{
    int x = fork();
    if (x > 0)
    {
        //parent, fork returns the child pid value
        printf("Daemon process id: %d\n", x);
        exit(0);
    }

    // help create a clean environment for the daemon process to run independently
    setsid(); //This function creates a new session if the calling process is not a process group leader
    chdir("/"); // This changes the current working directory of the process to the root directory ("/")
    umask(0); // all new files will have default premissions without any restrictions

    // clcose standard input, standard output, and standard error file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while(1){
        continue;
    }

}
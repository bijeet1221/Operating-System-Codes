// Program no: 26
// Name : Bijeet Basak(IMT2022510)
// Write a program to execute ls -Rl using
// the following system calls:
// a. execl
// b. execlp
// c. execle
// d. execv
// e. execvp

#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[], char *envp[])
{
    printf("Executes ls -Rl using execle");
    execle("/bin/ls", "/bin/ls", "-R", "-l", NULL, envp);
    return(0);
}
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

int main()
{
    printf("Executes ls -Rl using execv");
    char* arr[] = {"ls", "-R", "-l", NULL};
    execvp("ls", arr);
}

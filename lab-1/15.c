// Program no: 15
// Name : Bijeet Basak(IMT2022510)
// Create a program to display the environmental
// variables of the user, utilizing the environ variable.

#include <stdio.h>
extern char **environ; // Declare the external variable 'environ' which is an array of strings representing the environment variables

int main()
{
    int i=0;
    while(environ[i])
    {
        printf("%s\n",environ[i]);
        i++;
    }
}
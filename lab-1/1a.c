// Program no: 1
// Name : Bijeet Basak(IMT2022510)
// Utilize both shell commands and system calls to create the
// following types of files:
// a. soft link (using the symlink system call)


#include <stdio.h> 
#include <unistd.h> // allows to use symlink

int main() 
{
    printf("Enter file and soft link: ");
    char a[256],b[256];
    scanf("%s %s",a,b);
    if(symlink(a,b) == 0) 
        printf("Soft link created successfully.\n");
    else 
        printf("Error\n");
    return 0;
}


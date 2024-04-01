// Program no: 1
// Name : Bijeet Basak(IMT2022510)
// Utilize both shell commands and system calls to create the
// following types of files:
// b. hard link (using the link system call)


#include <stdio.h>
#include <unistd.h> // allows to use link 

int main() 
{
    printf("Enter file and hard link: ");
    char a[256],b[256];
    scanf("%s %s",a,b);
    if(link(a,b) == 0) 
        printf("Hard link created successfully.\n");
    else 
        printf("Error\n");
    return 0;
}


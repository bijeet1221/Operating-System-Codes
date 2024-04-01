// Program no: 28
// Name : Bijeet Basak(IMT2022510)
// Find out the priority of your running program
// and modify it using the nice command

#include <stdio.h>
#include <unistd.h> // allows to use getpid()
#include <sys/resource.h> // allows to get process priority

int main()
{
	int pid = getpid();
    int priority = getpriority(PRIO_PROCESS, pid);
    printf("Current priority: %d\n", priority);
    nice(10); // incrementing priority by 10
    priority = getpriority(PRIO_PROCESS, pid);
    printf("New priority of the process: %d\n", priority);
    return(0);
}
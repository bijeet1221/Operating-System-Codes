// Program no: 29
// Name : Bijeet Basak(IMT2022510)
// Write a program to obtain the scheduling policy
// and modify it (e.g., SCHED_FIFO, SCHED_RR).


#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main()
{
    printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));

    // Create a sched_param structure and set the scheduling priority to 20
    struct sched_param sp;
    sp.sched_priority = 20;

    // Set the scheduling policy of the process to SCHED_RR (Round Robin)
    sched_setscheduler(getpid(), SCHED_RR, &sp);
    printf("Scheduling policy changed to SCHED_RR\n");
    printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));

    // Set the scheduling policy of the process to SCHED_FIFO (First In, First Out)
    sched_setscheduler(getpid(), SCHED_FIFO, &sp);
    printf("Scheduling policy changed to SCHED_FIFO\n");
    printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));
}

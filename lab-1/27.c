// Program no: 27
// Name : Bijeet Basak(IMT2022510)
// Develop a program to retrieve the
// maximum and minimum real-time priority.


#include <stdio.h>
#include <unistd.h>
#include <sched.h> // allows to use sched commands

int main()
{
	printf("Max priority: %d\n", sched_get_priority_max(SCHED_RR));
	printf("Min priority: %d\n", sched_get_priority_min(SCHED_RR));
}
/*
* Name: pmod.c
* Author: Zeeshan Huq
* Assignment Name: Lab 9 System Calls
* Section Number: 111
* Date: 11/3/26
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

int main(void)
{
    sleep(3); // Sleep for 3 seconds so user can check process priority before and after the change
    errno = 0;
    int result = nice(10); // Reduce process priority by 10 and check for errors
    if (result == -1 && errno != 0)
    {
        perror("Error calling nice");
        return EXIT_FAILURE;
    }

    printf("New nice value: %d\n", result); 

    struct timespec req = { .tv_sec = 1, .tv_nsec = 837272638L }; // Sleep for 1.837272638 seconds to allow user to check process priority after the change
    struct timespec rem;
    
    while (nanosleep(&req, &rem) == -1) // Check for errors during sleep
    {
        if (errno != EINTR)
        {
            perror("Error calling nanosleep");
            return EXIT_FAILURE;
        }
        req = rem;
    }
    
    printf("Process completed after sleeping for 1.837272638 seconds.\n");

    return EXIT_SUCCESS;
}
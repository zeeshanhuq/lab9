/*
* Name: pinfo.c
* Author: Zeeshan Huq
* Assignment Name: Lab 9 System Calls
* Section Number: 111
* Date: 11/2/26
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sched.h>
#include <errno.h>

static const char *policy_to_string(int policy) // Convert scheduling policy to string representation
{
    switch (policy) {
        case SCHED_OTHER:
            return "SCHED_OTHER (normal)";
        case SCHED_FIFO:
            return "SCHED_FIFO (real-time, first-in, first-out)";
        case SCHED_RR:
            return "SCHED_RR (real-time, round-robin)";
    #ifdef SCHED_BATCH
        case SCHED_BATCH:
            return "SCHED_BATCH (batch processing)";
    #endif
    #ifdef SCHED_IDLE
        case SCHED_IDLE:
            return "SCHED_IDLE (idle scheduling)";
    #endif
    #ifdef SCHED_DEADLINE
        case SCHED_DEADLINE:
            return "SCHED_DEADLINE (deadline scheduling)";
    #endif
        default:
            return "UNKNOWN";
    }
}

int main(int argc, char* argv[])
{
    pid_t pid;
    if (argc > 2) { // Check if the correct number of arguments is provided
        fprintf(stderr, "Usage: %s [pid]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (argc == 2) { // If a PID is provided, convert it to a pid_t type and validate it
        char *endptr = NULL;
        errno = 0;
        long val = strtol(argv[1], &endptr, 10);
        if (errno != 0 || endptr == argv[1] || *endptr != '\0' || val <= 0) {
            fprintf(stderr, "Invalid PID: %s\n", argv[1]);
            return EXIT_FAILURE;
        }
        pid = (pid_t)val;
    } else {
        pid = getpid();
    }

    errno = 0;
    int priority = getpriority(PRIO_PROCESS, pid); // Get the priority of the process and check for errors
    if (priority == -1 && errno != 0) {
        fprintf(stderr, "Error getting priority for PID %d: %s\n", pid, strerror(errno));
        return EXIT_FAILURE;
    }

    int policy = sched_getscheduler(pid); // Get the scheduling policy of the process and check for errors
    if (policy == -1) {
        fprintf(stderr, "Error getting scheduling policy for PID %d: %s\n", pid, strerror(errno));
        return EXIT_FAILURE;
    }

    #ifndef SCHED_RESET_ON_FORK // If SCHED_RESET_ON_FORK is not defined, clear the flag from the policy
        policy &= policy & ~SCHED_RESET_ON_FORK;
    #endif

    // Print process information
    printf("PID: %d\n", pid);
    printf("Priority: %d\n", priority);
    printf("Scheduling Policy: %s\n", policy_to_string(policy));

    return EXIT_SUCCESS;
}
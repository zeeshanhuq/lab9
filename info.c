/*
* Name: info.c
* Author: Zeeshan Huq
* Assignment Name: Lab 9 System Calls
* Section Number: 111
* Date: 10/29/26
*/

#include <time.h> //clock_gettime
#include <unistd.h> //gethostname , sysconf , getpagesize
#include <sys/utsname.h> //uname
#include <sys/sysinfo.h> //get_nprocs
#include <stdio.h>


int main(int argc, char* argv[])
{
    struct timespec time;
    struct utsname sysinfo;

    if(clock_gettime(CLOCK_REALTIME, &time) ==0){
        long int nanosec = (time.tv_sec * 1000000000) + time.tv_nsec;
        printf("The current time in nanoseconds is: %ld \n", nanosec);
    }

    if(uname(&sysinfo) == 0){
        printf("System's network name: %s\n", sysinfo.nodename);
        printf("Operating system name: %s\n", sysinfo.sysname);
        printf("Operating system release: %s\n", sysinfo.release);
        printf("Operating system version: %s\n", sysinfo.version);
        printf("System's hardware type: %s\n", sysinfo.machine);
    }

    int processors;
    if((processors = get_nprocs()) != 0){
        printf("Number of CPUs in system: %d\n", processors);
    }


    return 0;
}
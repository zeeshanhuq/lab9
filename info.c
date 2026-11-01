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
    struct timespec time; //struct to hold time
    struct utsname sysinfo; //struct to hold system information

    if(clock_gettime(CLOCK_REALTIME, &time) ==0){ //check if clock_gettime was successful
        long int nanosec = (time.tv_sec * 1000000000) + time.tv_nsec; //convert seconds to nanoseconds and add nanoseconds
        printf("The current time in nanoseconds is: %ld \n", nanosec);
    }

    if(uname(&sysinfo) == 0){ //check if uname was successful
        printf("System's network name: %s\n", sysinfo.nodename);
        printf("Operating system name: %s\n", sysinfo.sysname);
        printf("Operating system release: %s\n", sysinfo.release);
        printf("Operating system version: %s\n", sysinfo.version);
        printf("System's hardware type: %s\n", sysinfo.machine);
    }

    int processors; //variable to hold number of processors
    if((processors = get_nprocs()) != 0){ //check if get_nprocs was successful
        printf("Number of CPUs in system: %d\n", processors);
    }

    long physmem = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE); //calculate physical memory in bytes
    printf("Physical memory in bytes: %ld\n", physmem);

    long freemem = sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGESIZE); //calculate free memory in bytes
    printf("Free memory in bytes: %ld\n", freemem);
    
    return 0;
}
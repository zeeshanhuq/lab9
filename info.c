/*
* Name: info.c
* Author: Zeeshan Huq
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



    return 0;
}
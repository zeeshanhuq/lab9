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
    struct timespec tp;
    if(clock_gettime(CLOCK_REALTIME, &tp) ==0){
        long int nanosec = (tp.tv_sec * 1000000000) + tp.tv_nsec;
        printf("The current time in nanoseconds is: %ld \n", nanosec);
    }

    

    return 0;
}
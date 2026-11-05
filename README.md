# Lab 9 System Calls

info.c:  

Uses the system call clock_gettime with the parameter clock_realtime to get the current time. the seconds and nanoseconds are stored in a struct. The seconds are then converted to nanoseconds and added to the other nanoseconds. The total time is then printed if none of the values are blank.  

Uses the system call utsname to get the systems information. Information includes the network name, operating system name, operating system release, operating system version, and the system's hardware type. All these are printed if none of the values are blank.  

Uses the system call get_nprocs to get the number of processors in the system. If the number is non-zero (indicating a sucessful call), the number of processors is printed.  

Uses the system call sysconf to find the amount of physical memory in the system. This is done with sysconf with the parameter of _SC_PHYS_PAGES to find the number of pages of physical memory, multiplied by sysconf with the parameter of _SC_PAGESIZE to find how much memory is in a page. This result is then printed out.  

Uses the system call sysconf to find the amount of free memory in the system. This is done with sysconf with the parameter of _SC_AVPHYS_PAGES to find the number of pages of free memory, multiplied by sysconf with the parameter of _SC_PAGESIZE to find how much memory is in a page. This result is then printed out.   

pinfo.c:  

Uses getpriority and sched_getscheduler and print the policy as text. Defaults to itself with no paramaters, or gives an error and exits on bad/nonexistent PIDs.   

pmod.c:  

Sleeps for a 3 so user can see current priority, then uses nice to reduce its priority by 10. Then it sleeps with nanosleep for 1,837,272,638 nanoseconds. Finally gives a goodbye message and exits.  

finfo.c:  

Uses mode_t to find file attributes. A switch case with mode and an S_IFMT bit mask is used to find the file type. Mode is also used to know the file permissions. Checks the arguments entered and prints the file information if a proper file is entered. Otherwise, prints an error.
How to use: call ./finfo (filename)
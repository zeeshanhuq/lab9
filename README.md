# Lab 9 System Calls

info.c: \
Uses the system call clock_gettime with the parameter clock_realtime to get the current time. the seconds and nanoseconds are stored in a struct. The seconds are then converted to nanoseconds and added to the other nanoseconds. The total time is then printed if none of the values are blank. \
Uses the system call utsname to get the systems information. Information includes the network name, operating system name, operating system release, operating system version, and the system's hardware type. All these are printed if none of the values are blank. \
Uses the system call get_nprocs to get the number of processors in the system. If the number is non-zero (indicating a sucessful call), the number of processors is printed. \
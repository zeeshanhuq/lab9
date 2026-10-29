# Lab 9 System Calls

Info.C:\
Uses the system call clock_gettime with the parameter clock_realtime to get the current time. the seconds and nanoseconds are stored in a struct. The seconds are then converted to nanoseconds and added to the other nanoseconds. The total time is then printed if the system was successful in execution.
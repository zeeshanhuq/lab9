/*
* Name: finfo.c
* Author: Zeeshan Huq
* Assignment Name: Lab 9 System Calls
* Section Number: 111
* Date: 11/5/26
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

static const char *filetype(mode_t mode)
{
    switch (mode & S_IFMT) { //file type mask
        case S_IFBLK:  return "block device";
        case S_IFCHR:  return "character device";
        case S_IFDIR:  return "directory";
        case S_IFIFO:  return "FIFO/pipe";
        case S_IFLNK:  return "symlink";
        case S_IFREG:  return "regular file";
        case S_IFSOCK: return "socket";
        default:       return "unknown?";
    }
}

static void *permission_string(mode_t mode) // file permission string
{
    static char perms[10];
    perms[0] = (mode & S_IRUSR) ? 'r' : '-';
    perms[1] = (mode & S_IWUSR) ? 'w' : '-';
    perms[2] = (mode & S_IXUSR) ? 'x' : '-';
    perms[3] = (mode & S_IRGRP) ? 'r' : '-';
    perms[4] = (mode & S_IWGRP) ? 'w' : '-';
    perms[5] = (mode & S_IXGRP) ? 'x' : '-';
    perms[6] = (mode & S_IROTH) ? 'r' : '-';
    perms[7] = (mode & S_IWOTH) ? 'w' : '-';
    perms[8] = (mode & S_IXOTH) ? 'x' : '-';
    perms[9] = '\0';
    return perms;
}

int main(int argc, char* argv[])
{
    if(argc != 2) { // Check if the correct number of arguments is provided
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat sb;
    if(stat(argv[1], &sb) == -1) { // Get file status and check for errors
        fprintf(stderr, "Error occurred while getting file status: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Print file information
    printf("File: %s\n", argv[1]);
    printf("File type: %s\n", filetype(sb.st_mode));
    printf("Permissions: %s\n", (char *)permission_string(sb.st_mode));
    printf("Owner UID: %d\n", sb.st_uid);
    printf("Size: %ld bytes\n", sb.st_size);
    printf("Last modified: %s", ctime(&sb.st_mtime));

    return EXIT_SUCCESS;
}
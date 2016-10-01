#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int fd;
    char *filename;
    int flags = O_WRONLY | O_CREAT;
    int mode = S_IRWXU | S_IXGRP | S_IRWXG | S_IROTH | S_IXOTH;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    filename = argv[1];

    fd = open(filename, flags, mode);
    if (fd == -1) {
        fprintf(stderr, "Err. open() failed: %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    close(fd);
    return(EXIT_SUCCESS);
}

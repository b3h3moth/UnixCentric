#define _LARGEFILE64_SOURCE // Working with large files
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    off64_t offset;
    int fd;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s [filename, offset]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open64(argv[1], O_RDWR | O_CREAT);
    if (fd == -1) {
        fprintf(stderr, "Failed to open file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}

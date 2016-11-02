#define _LARGEFILE64_SOURCE // Working with large files
#define _FILE_OFFSET_BITS 64

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

    offset = atoll(argv[2]);
    
    if (lseek64(fd, offset, SEEK_SET) == -1) {
        fprintf(stderr, "seek failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (write(fd, "filetest.txt", 4) == -1) {
        fprintf(stderr, "write() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}

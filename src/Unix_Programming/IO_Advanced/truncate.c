#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

enum { SIZE = 512, FILE_SIZE = 2025 };

int main(int argc, char *argv[]) {
    int in_fd, out_fd, nr;
    char buf[FILE_SIZE];
    int in_flags = O_RDONLY;
    int out_flags = O_WRONLY | O_CREAT;
    int out_mode = S_IRWXU | S_IXGRP | S_IRWXG | S_IROTH | S_IXOTH;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename>.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    in_fd = open(argv[1], in_flags);
    if (in_fd == -1) {
        fprintf(stderr, "Err. open() input failed: %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    out_fd = open(argv[2], out_flags, out_mode);
    if (out_fd == -1) {
        fprintf(stderr, "Err. open() output failed: %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if ((nr = read(in_fd, buf, FILE_SIZE)) != -1)
        write(out_fd, buf, FILE_SIZE);

    close(in_fd);
    close(out_fd);

    truncate(argv[2], SIZE);
    return(EXIT_SUCCESS);
}

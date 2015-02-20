#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[]) {
    int input_fd, file_flags;
    mode_t file_perms;
    char BUF[BUF_SIZE];

    /* Il file sara' creato, o per lo meno dovrebbe esserlo, con i seguenti
    permessi: rw-rw-rw (0666).

    Solo uno tra O_RDWR, O_RDONLY e O_WRONLY dovrebbe essre specificato in
    flags. */

    file_flags = O_RDWR | O_CREAT | O_EXCL | O_TRUNC;
    file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((input_fd = open(argv[1], file_flags, file_perms)) < 0) {
        fprintf(stderr, "Err. opening %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((close(input_fd)) < 0) {
        fprintf(stderr, "Err. close(%s)\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define FILE_PERMS (S_IRUSR | S_IWUSR |S_IRGRP | S_IWGRP |S_IROTH | S_IWOTH)

int main(int argc, char *argv[]) {
    int fd;     /* File descriptor */

    if (argc < 3 || strncmp(argv[1], "--help", 6)  == 0) {
        fprintf(stderr, "Usage: %s <filename> [r|R|w!s]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Apri un file in lettura/scrittura, se non esiste e' necessario crearlo,
    dovra' essere settato con i permessi impostati a rw-rw-rw */
    if ((fd = open(argv[1], O_RDWR | O_CREAT, FILE_PERMS)) == -1) {
        fprintf(stderr, "Err. open(%s): %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}

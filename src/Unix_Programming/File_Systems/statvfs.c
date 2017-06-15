#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <errno.h>
#include <sys/statvfs.h>

/* Lo scopo del programma e' di ottenere informazioni su un file system montato.
Il device relativo al file siystem viene fornito in input. */

int main(int argc, char *argv[]) {
    char *pathname = NULL;
    size_t len = 0;
    int my_err = 0;
    errno = 0;
    struct statvfs device;

    if (argc != 2) {
        fprintf(stdout, "Usage: %s 'pathname'\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    len = strlen(argv[1]) + 1;
    pathname = malloc(len * sizeof(char));
    strncpy(pathname, argv[1], len);

    if (statvfs(pathname, &device) == -1) {
        my_err = errno;
        fprintf(stdout, "Err.%d statvfs(); %s\n", my_err, strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("%13s: %s\n", "file system", pathname);
    printf("%13s: %lu\n", "fs block size", device.f_bsize);

    free(pathname);

    return(EXIT_SUCCESS);
}

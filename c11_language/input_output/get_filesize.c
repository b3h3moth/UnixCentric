#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

/* Lo scopo del programma e' di restituire la grandezza di un file regolare in
modo sicuro. Soluzione POSIX compilant. */

int main(int argc, char *argv[]) {
    struct stat stbuf;
    off_t size;
    char *buf;
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Err. Can't open file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if ((fstat(fd, &stbuf) != 0) || (!S_ISREG(stbuf.st_mode))) {
        fprintf(stderr, "Err. Can't fstat file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return(EXIT_SUCCESS);
}

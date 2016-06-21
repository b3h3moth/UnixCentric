#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Lo scopo del programma e' di restituire la grandezza di un file regolare in
modo sicuro. Soluzione POSIX compilant. */

int main(int argc, char *argv[]) {
    struct stat stbuf;
    off_t size;
    char *buf;
    int fd;

    fd = open(argv[1], O_RDONLY);
    return(EXIT_SUCCESS);
}

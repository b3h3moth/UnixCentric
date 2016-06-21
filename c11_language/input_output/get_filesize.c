#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/* Lo scopo del programma e' di restituire la grandezza di un file regolare in
modo sicuro.

Soluzione POSIX compilant*/

int main(void) {
    struct stat stbuf;
    off_t size;
    char *buf;
    int fd;

    fd = open("
    return(EXIT_SUCCESS);
}

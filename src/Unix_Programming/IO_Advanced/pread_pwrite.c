#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/* Lo scopo del programma e' di leggere un file in input, stabilirne offset e 
size, dopodiche' il contenuto da offset a size puo' essere scritto tutto o in
parte in un file di output, poiche' anche nel file di output si deve impostare
sia offset sia size. 

$ ./a.out infile 100 50 outfile 0 50*/

int main(int argc, char *argv[]) {
    char *buf;
    int in_fd, out_fd, nread;
    off_t in_offst, out_offst;
    size_t in_size, out_size;

    if (argc != 7) {
        fprintf(stderr, "Usage: %s <input file, offset, size>"
                " <output file, offset, size>", argv[0]);
        exit(EXIT_FAILURE);
    }

    in_fd = open(argv[1], O_RDONLY);
    if (in_fd < 0) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    out_fd = open(argv[4], O_CREAT | O_WRONLY, S_IRWXU);
    if (out_fd < 0) {
        fprintf(stderr, "Unable to write %s: %s\n", argv[4], strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Setup input output offset
    in_offst = strtol(argv[2], NULL, 10);
    out_offst = strtol(argv[5], NULL, 10);

    // Set up input output size
    in_size = strtol(argv[3], NULL, 10);
    out_size = strtol(argv[6], NULL, 10);

    buf = malloc(sizeof(in_size));

    if (in_size < out_size)
        out_size = in_size;

    /* Si usano le funzioni pread() e pwrite() per leggere e scrivere da uno
    specifico offset */
    nread = pread(in_fd, buf, in_size, in_offst);
    pwrite(out_fd, buf, nread, out_offst);

    return(EXIT_SUCCESS);
}

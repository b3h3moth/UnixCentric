#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Lo scopo del programma e' di leggere un file in input, calcolarne la 
grandezza, e copiare l'intero contenuto in un altro file, dopodiche' si calcola
la meta' esatta del file originario e si provvede a troncare il nuovo file alla
grandezza calcolata, ovvero la meta'. Il troncamento sara' eseguito mediante la
funzione truncate(). */

int main(int argc, char *argv[]) {
    int in_fd, out_fd, nr;
    struct stat st;
    ssize_t in_fsize, new_size;
    char *buf;
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

    /* Effettua uno stat del file di input in modo tale da ricavarne la
    grandezza e allocare la memoria necessaria per copiarlo esattamente nel
    file di output. */
    if (fstat(in_fd, &st) == -1) {
        fprintf(stderr, "Err. fstat() inpput failed: %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    in_fsize = st.st_size;
    buf = malloc(sizeof(in_fsize));

    if ((nr = read(in_fd, buf, in_fsize)) != -1)
        write(out_fd, buf, in_fsize);

    close(in_fd);

    // Troncamento del file della meta' della grandezza originaria
    ((in_fsize % 2) == 0) ? \
        (new_size = in_fsize / 2) : (new_size = (in_fsize - 1)/2);

    if (truncate(argv[2], new_size) == -1) {
        fprintf(stderr, "Err. truncate() failed: %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (fstat(out_fd, &st) == -1) {
        fprintf(stderr, "Err. fstat() inpput failed: %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("The original size of \'%s\': %d\n", argv[1], in_fsize);
    printf("The size after truncation of \'%s\': %d\n", argv[2], in_fsize);

    close(out_fd);
    return(EXIT_SUCCESS);
}

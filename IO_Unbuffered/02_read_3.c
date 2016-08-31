#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/* Lo scopo del programma e' la lettura di un file ricevuto in input, stampando
un carattere alla volta sullo stream di output. */

int main(int argc, char *argv[]) {
    int fd, n;
    char buf;

    if (argc < 2) {
       fprintf(stderr,"Uso: %s <file name>\n", argv[0]);
       exit(EXIT_FAILURE);
    }

    if ( (fd = open(argv[1], O_RDONLY)) < 0) {
       fprintf(stderr, "Err. open file\n");
       exit(EXIT_FAILURE);
    }

    /* Lettura del file un carattere alla volta e stampa immediata in output
    del carattere stesso. */
    while ((n = read(fd, &buf, 1)) > 0)
       write(STDOUT_FILENO, &buf, n);
    
    close(fd);

    return(EXIT_SUCCESS);
}

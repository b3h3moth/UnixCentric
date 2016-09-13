#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <string.h>

#define MAX_BUF 4096

/*
HEADER    : <unistd.h>
PROTOTYPE : ssize_t read(int fd, void *buf, size_t nbytes);
SEMANTICS : La funzione read() legge 'nbytes' byte dalla posizione corrente
            del file descriptor 'fd' nel buffer 'buf'.
RETURNS   : Il numero dei byte letti in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

/* Lo scopo del programma e' la lettura di un file ricevuto in input, la stampa
in output e' affidata system call write(). */

int main(int argc, char *argv[]) {
    int fd;
    ssize_t n;
    char buf[MAX_BUF+1];

    if (argc < 2) {
        fprintf(stderr, "Uso: %s <file name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        fprintf(stderr, "Err. open file\n");
        exit(EXIT_FAILURE);
    }

    /* La funzione read(), legge MAX_BUF byte dal file descriptor 'fd' e li 
    pone, senza alcuna conversione, in buf; ritorna il numero di byte letti, 
    oppure -1 in caso di fallimento. */
    if ((n = read(fd ,buf, MAX_BUF)) < 0) {
        fprintf(stderr, "Err. read file\n");
        exit(EXIT_FAILURE);
    }

    /* E' sempre una buona pratica, allorquando non si lavora con dati binari,
    inserire il carattere 'null-terminato' finale */
    buf[n] = '\0';

    /* La funzione write() risulta essere particolarmente efficiente in questo
    caso */
    if (write (STDOUT_FILENO, buf, n) < 0) {
        fprintf(stderr, "Err. write file\n");
        exit(EXIT_FAILURE);
    }

    close(fd);

   return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LEN 80

/* Lo scopo del programma e' di stampare un file ricevuto in input, in ordine
inverso. La stampa avverra' dalla fine all'inizio del file e carattere per
carattere. Si utilizzeranno le funzioni fseek() per spostarsi alla fine
del file e ftell() per acquisire la posizione. */

int main(int argc, char *argv[]) {
    FILE *fp;
    int ch;
    unsigned long last;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Sposta il file pointer alla fine del file, salva inoltre la posizione
    del file pointer stesso, ovvero il numero dei byte del file */
    if (fseek(fp, 0, SEEK_END) != -1)
        last = ftell(fp);

    /* Stampa il file in ordine inverso, settando di volta in volta il file
    pointer al carattere da stampare mediante la funzione fseek() */
    for (long i=1; i<last; i++)
        if (fseek(fp, -i, SEEK_END) != -1)
            putchar(ch = getc(fp));

    fclose(fp);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN 31

/* Lo scopo del programma e' di scrivere una serie di stringhe in un file
ricevute da stdin, dopodiche' si spostera' il 'file pointer' all'inizio del
file stesso e sara' letto e stampato su stdout. */


int main(void) {
    FILE *fp;
    char buf[MAX_LEN];
    char *filename = "data.txt";

    if ((fp = fopen(filename, "a+")) == NULL) {
        fprintf(stderr, "Err. fopen(); %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Enter strings to add to \'%s\' (press ? to terminate)\n", filename);
    // Ricezione delle stringhe in input, e scrittura delle stesse sul file
    while ((fscanf(stdin, "%30s", buf) == 1) && (buf[0] != '?'))
        fprintf(fp, "%s ", buf);


    /* Ci si sposta all'inizio del file, e poiche' il file stesso e' stato
    aperto in modalita' 'a+' (append) leggera' tutto cio' che e' stato scritto
    nelle varie esecuzione del programma */
    if (fseek(fp, 0L, SEEK_SET) == -1) {
        fprintf(stderr, "Err. fseek(); %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s", buf) != -1)
        fprintf(stdout, "%s ", buf);

    fclose(fp);
    return(EXIT_SUCCESS);
}

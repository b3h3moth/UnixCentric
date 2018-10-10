#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_LEN 50
#define MIN_STR_LEN 5

void get_ascii(char *name, FILE *f_in);

/* Lo scopo del programma e' di elaborare un file binario in input ed 
estrapolare da esso tutte le stringhe stampabili e stamparle mediante un buffer
di dimensione compresa tra MIN_STR_LEN e MAX_STR_LEN. */

int main(int argc, char *argv[]) {
    int i;
    FILE *f_in;

    if (argc == 1) {
        fprintf(stderr, "Usage: %s <filename/s>\n", argv[0]);
        exit(EXIT_FAILURE);
    } 

    for (i=1; i<argc; i++) {
        if ((f_in = fopen(argv[i], "rb")) == NULL) {
            fprintf(stderr, "Err. open file\n");
            exit(EXIT_FAILURE);
        } else {
            get_ascii(argv[i], f_in);
            fclose(f_in);
        }
    }

    return(EXIT_SUCCESS);
}

void get_ascii(char *name, FILE *f_in) {
    int c, i;
    char buf[MAX_STR_LEN];

    do {
        for (i=0; (c = fgetc(f_in)) != EOF; ) {
            if (!isprint(c))
                break;

            buf[i++] = c;

            if (i >= MAX_STR_LEN)
                break;
        }

        /* Stampa solo se la stringa ricevuta in input risulta essere
        sufficientemente lunga; MIN_STR_LEN infatti definisce la grandezza
        minima delle stringhe da elaborare. */
        if (i >= MIN_STR_LEN)
            printf("%s:%.*s\n", name, i, buf);
    } while (c != EOF);
}

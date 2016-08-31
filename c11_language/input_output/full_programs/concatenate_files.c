#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

enum { BUF_MAX = 64 };

/* Lo scopo del programma e' di stampare su stdout uno o piu' file ricevuti
in input, una sorta di simulazione del comando 'cat' */

int main(int argc, char *argv[]) {
    char buf[BUF_MAX];
    FILE *fin;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename, ...>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Inizializza a 0 ciascun elemento dell'array buf[]
    if (memset(buf, 0, BUF_MAX) == NULL) {
        fprintf(stderr, "Err. memset(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (int i=1; i<argc; i++) {
        if ((fin = fopen(argv[i], "r"))) {
            while (fgets(buf, BUF_MAX, fin)) {
                fputs(buf, stdout);
            }
            fclose(fin);
        } else {
            fprintf(stderr, "Err. fopen(); %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>

/* Lo scopo del programma e' di ricevere un file in input come argomento, di
stampare su stdout il contenuto del file, di contare ciascun carattere del file
stesso, ponendo un limite al numero massimo di caratteri da salvare. */

int main(int argc, char argv[]) {
    int ch;
    File *fp;
    uint32_t count = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Legge 'char by char' salvando di volta in volta il toale dei caratteri

    return(EXIT_SUCCESS);
}

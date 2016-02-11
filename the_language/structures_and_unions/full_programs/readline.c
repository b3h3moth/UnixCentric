#include <stdio.h>
#include <ctype.h>
#include "readline.h"

/* Salta gli spazi vuoti, legge il resto della riga in input, se e' maggiore
di 'n' la tronca, infine la salva in 'str'. */
int read_line(char str[], int n) {
    int c, i = 0;

    // Salta gli spazi vuoti
    while (isspace(c = fgetc(stdin)))
        ;

    while (c != '\n' && c != EOF) {
        if (i < n)
            str[i++] = c;
        c = fgetc(stdin);
    }
    // Null-character di fine stringa
    str[i] = '\0';
    return i;
}

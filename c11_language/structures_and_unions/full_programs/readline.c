#include <stdio.h>
#include <ctype.h>
#include "readline.h"

int read_line(char str[], int n) {
    int c, i = 0;

    // Salta gli spazi vuoti
    while (isspace(c = fgetc(stdin)))
        ;

    /* Legge il resto della riga, salva l'input nella stringa 'str' solo se
    e' minore di 'n' */
    while (c != '\n' && c != EOF) {
        if (i < n)
            str[i++] = c;
        c = fgetc(stdin);
    }
    // Aggiunge il null-character di fine stringa
    str[i] = '\0';

    // Restituisce il numero dei caratteri memorizzati nella stringa 'str'
    return i;
}

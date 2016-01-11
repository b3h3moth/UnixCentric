#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Prototipe: char *strdup(const char *str);

La funzione strdup() e similari non fanno parte dello standard c ansi, tuttavia
nei sistemi Unix e' ampiamente utilizzata.

Lo scopo della funzione e' di duplicare la stringa 'str', restituendo un
puntatore ad essa in caso di successo.
*/

int main(void) {
    char str[] = "Get up stand up, stand up for your rights";
    char *dup_str;

    dup_str = strdup(str);

    printf("%s\n", dup_str);

    return(EXIT_SUCCESS);
}

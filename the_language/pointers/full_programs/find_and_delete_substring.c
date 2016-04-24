#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *match(char *source, char *str);
char *delete_substring(char *source,  char *substr);

/* Lo scopo del programma e' di creare una funzione che cerchi una
sottostringa all'interno di una stringa, individuarla e stamparla dal punto
dell'individuazione fino alla fine */

int main(void) {
    char *buf = "Get up Stand up, Stand up for your rights, Bob Marley";
    char *str = "Bob";

    char *res = delete_substring(buf, str);
    printf("%s\n", res);


    return(EXIT_SUCCESS);
}

char *match(char *source, char *str) {
    while (*str != '\0')
        if (*source++ != *str++)
            return NULL;

    return source;
}

char *delete_substring(char *source,  char *substr) {
    char *next;

    // Cerca la prima occorrenza della sottostringa
    while (*source != '\0') {
        next = match(source, substr);
        
        if (next != NULL)
            break;
        source++;
    }

    // La sottostringa non e' stata individuata
    if (*source == '\0')
        return NULL;

    // La sottostringa e' stata individuata 
    while ((*source == *next)) {
        *source++ = *next++;
    }

    return source;
}

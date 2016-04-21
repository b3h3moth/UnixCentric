#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *match(char *source, *str);
int delete_substring(char *source,  char const *substr);

int main(void) {
    return(EXIT_SUCCESS);
}

char *match(char *source, *str) {
    while (*str != '\0')
        if (*source++ != *str++)
            return NULL;

    return source;
}

int delete_substring(char *source,  char const *substr) {
    char *next;

    // Cerca la prima occorrenza della sottostringa
    while (*source != '\0') {
        *next = match(source, substr);
        
        if (next != NULL)
            break;
        source++;
    }

    // La sottostringa non e' stata individuata
    if (*source == '\0')
        return false;

    // La sottostringa e' stata individuata e si provvede alla cancellazione
    while (*source = *next++)
        ;

    return true;
}

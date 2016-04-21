#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *match(char *source, char *str);
bool delete_substring(char *source,  char *substr);

int main(void) {
    char *buf = "Get up Stand up, Stand up for your rights, Bob Marley";
    char *str = "Bob";

    bool res = delete_substring(buf, str);

    if (res) {
        printf("%s\n", buf);
    } else
        puts("false");

    return(EXIT_SUCCESS);
}

char *match(char *source, char *str) {
    while (*str != '\0')
        if (*source++ != *str++)
            return NULL;

    return source;
}

bool delete_substring(char *source,  char *substr) {
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
        return false;

    // La sottostringa e' stata individuata e si provvede alla cancellazione
    while ((*source == *next)) {
        *source++ = *next++;
    }

    printf("%s\n", source);
    printf("%s\n", next);

    return true;
}

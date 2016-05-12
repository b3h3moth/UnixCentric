#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
int match(char *regexp, char *text);
int matchere(char *regexp, char *text);
int matchstar(int c, char *regexp, char *text);

int main(void) {
    return(EXIT_SUCCESS);
}

/* Cerca 'regexp' nel testo 'text'. Determina se una stringa soddisfa o meno
una regular expression */
int match(char *regexp, char *text) {
    /* Se la regex inizia con ^, la parte iniziale del testo deve soddisfare
       la restante parte dell'espressione. */
    if (regexp[0] == '^')
        return matchere(regexp + 1, text);

    // Cerca se la stringa e' vuota
    do {
        if (matchere(regexp, text))
            return 1;
    } while (*text++ != '\0');

    return 0;
}

// Cerca 'regexp' all'inizio del testo 'text'
int matchere(char *regexp, char *text) {
    if (regexp[0] == '\0')
        return 1;
    if (regexp[1] == '*')
        return matchstar(regexp[0], regexp + 2, text);
    if (regexp[0] == '$' && regexp[1] == '\0')
        return *text == '\0';
    if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
        return matchere(regexp + 1, text + 1);

    return 0;
}

// Cerca la regex '*' all'inizio del testo 'text'
int matchstar(int c, char *regexp, char *text) {
    do {
        if (matchere(regexp, text))
            return 1;
    } while (*text != '\0' && (*text++ == c || c == '.'));

    return 0;
}

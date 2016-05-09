#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
int match(char *regexp, char *text);
int matchere(char regexp, char *text);

int main(void) {
    return(EXIT_SUCCESS);
}

// Determina se una stringa di testo soddisfa una regular expression
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

int matchere(char regexp, char *text) {
    if (regexp[0] == '\0')
        return 1;
    if (regexp[1] == '*')
        return matchstar(regexè[0], regexp + 2, text);
    if (regexp[0] == '$' && regexp[1] == '\0')
        return *text == '\0';
    if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
        return matchere(regexp + 1, text + 1);

    return 0;
}

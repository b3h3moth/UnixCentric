#include <stdio.h>
#include <stdlib.h>

// Function  prototype
char *find_occurence(char const *source, char const *str);

int main(void) {
    return(EXIT_SUCCESS);
}

/* Lo scopo della funzione find_occurence() e' di trovare la prima occorrenza
di ciascun carattere della stringa 'str' nella stringa 'source'. 
Restituisce un puntatore al primo caratere trovato, altrimenti NULL. */
char *find_occurence(char const *source, char const *str) {
    char *tmp;

    if (source != NULL && str != NULL) {
        // Verifica 'source' un carattere alla volta
        for ( ; *source != '\0'; source++) {
            // Confronta ciascun carattere di 'source' con ciascun carattere 
            // di 'src'
            for (tmp = str; *tmp != '\0'; tmp++)
                if (*source == *tmp)
                    return source;
        }
    }

    return NULL;
}

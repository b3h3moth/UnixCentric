#include <stdio.h>
#include <stdlib.h>

// Function  prototype
char *find_occurence(char const *source, char const *str);

int main(void) {
    char *buf = "take a walk on the wild side, lou reed";
    char *str = "hi";

    char *temp = find_occurence(buf, str);
    printf("%s\n", temp);

    return(EXIT_SUCCESS);
}

/* Lo scopo della funzione find_occurence() e' di trovare la prima occorrenza
di ciascun carattere della stringa 'str' nella stringa 'source'. 
Restituisce un puntatore al primo caratere trovato, altrimenti NULL. */
char *find_occurence(char const *source, char const *str) {
    char *tmp;

    if (source != NULL && str != NULL)
        for ( ; *source != '\0'; source++)
            for (tmp = str; *tmp != '\0'; tmp++)
                if (*source == *tmp)
                    return source;

    return NULL;
}

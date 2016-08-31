#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE    ( sizeof(names) / sizeof(names[0]) )

/* Lo scopo del programma e' di inserire due stringhe in un array di puntatori
gia' inizializzato. */

int main(void) {
    char *names[] = {
        "francesca",
        "claudia",
        "xxx",
        "isabella",
        "xxx",
        "deborah",
    };

    char namea[] = "rossella";
    char nameb[] = "lodovica";

    /* Per copiare la stringa 'name' - tecnicamente e' unarray di caratteri -
    all' interno di un campo 'names' si puo' procedere mediante l'allocazione
    dinamica della memoria, nello specifico con la funzione calloc() che
    consente anche l'inizializzazione a 0 di ciascun elemento. */
    names[2] = calloc(strlen(namea)+1, sizeof(char));
    strcpy(names[2], namea);

    /* Tuttavia il modo migliore per copiare una stringa, allorquando si lavora
    con array of puntatori, e' di salvare semplicemente il puntatore della 
    nuova stringa. */
    names[4] = &nameb[0];

    // La stampa a video dell'array con la nuova fisionomia
    for (int i=0; i<ARR_SIZE; i++)
        printf("%s\n", names[i]);

    return(EXIT_SUCCESS);
}

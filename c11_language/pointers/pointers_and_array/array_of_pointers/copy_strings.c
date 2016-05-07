#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *names[] = {
        "francesca",
        "claudia",
        "xxx",
        "isabella",
        "xxx",
        "deborah",
        NULL
    };

    char name[] = "rossella";

    /* Per copiare la stringa 'name' - tecnicamente e' unarray di caratteri -
    all' interno di un campo 'names' si puo' procedere mediante l'allocazione
    dinamica della memoria, nello specifico con la funzione calloc() che
    consente anche l'inizializzazione a 0 di ciascun elemento. */
    names[2] = calloc(strlen(name)+1, sizeof(char));
    strcpy(names[2], name);

    /* Tuttavia il modo migliore per copiare una stringa, allorquando si lavora
    con array of puntatori, e' di salvare semplicemente il puntatore della 
    nuova stringa. */
    names[4] = &name[0];

    return(EXIT_SUCCESS);
}

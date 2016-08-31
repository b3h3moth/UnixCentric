#include <stdio.h>
#include <stdlib.h>

void sum(int *number, unsigned short esp);

int main(void) {
    int val = 2;
    int *ptr = &val;

    /* Il puntatore 'ptr' passato come argomento alla funzione 'sum()'
    contiene l'indirizzo della variabile 'val', pertanto andra' a modificare
    il valore della variabile stessa.
    
    I  puntatori sono lvalue, e come tali sono oggetti di assegnamento. */

    sum(ptr, 3);
    printf("%d\n", val);

    /* Si sarebbe potuto passare alla funzione l'indirizzo della variabile 
    'val', ottenendo il medesimo risultato. */

    sum(&val, 10);
    printf("%d\n", val);

    return(EXIT_SUCCESS);
}

void sum(int *number, unsigned short esp) {
    for (int i=1; i<esp; i++) 
        *number += *number;
}

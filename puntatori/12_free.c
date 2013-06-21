#include <stdio.h>
#include <stdlib.h>

/* L'allocazione dinamica della memoria consente il rilascio della memoria
stessa quando non piu' utilizzata, a tale scopo si usa la funzione free(), il
cui argomento deve essere un puntatore ad un indirizzo di memoria allocato con
malloc(), calloc() o realloc().

Nota: La memoria liberata sara' rilasciata sullo heap.

HEADER    : <stdlib.h>
PROTOTYPE : void free(void *ptr);
SEMANTICS : La funzione free() rilascia lo spazio di memoria puntato da 'ptr'.
RETURNS   : Non ritorna alcun valore.
--------------------------------------------------------------------------------
Se alla funzione free() gli si dovesse passare NULL, non succedera' alcunche'.
*/

int main(void) {
    int *ptr;
    /* Si alloca la memoria per contenere un tipo di dato intero */
    ptr = (int*) malloc(sizeof(int));
    /* Lo spazio di memoria viene ora rilasciato */
    free(ptr);

    /* Nessun cambiamento nel programma */
    free(NULL);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

#define N 10

/* L'allocazione dinamica della memoria consente l'allocazione di memoria sullo
heap, le funzioni principali con cui confrontarsi sono malloc(), calloc(), 
realloc() e free().

La funzione malloc() alloca un blocco di memoria sullo heap, il numero di byte
da allocare e' indicato dall'unico argomento, in caso di esito negativo sara'
restituito NULL.

HEADER    : <stdlib.h>
PROTOTYPE : void *malloc(size_t size);
SEMANTICS : La funzione malloc alloca 'size' byte di memoria sullo heap.
RETURNS   : L'indirizzo della locazione di memoria piu' bassa del blocco di 
            memoria allocato in caso di successo, NULL in caso di errore.
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    /* Allocazione di un intero */
    int *ptr;
    ptr = (int*)malloc(sizeof(int));  
    *ptr = 100;
    free(ptr);   /* Rilascio della memoria */

    /* 4 byte per un intero, utilizzare sizeof() rende il codice portabile; le
    seguenti istruzioni sono del tutto equivalenti, il blocco di memoria 
    allocato sullo heap sara' sempre di 4 byte.

    int size1 = sizeof(int);
    int size2 = 4;
    
    ptr = (int*)malloc(size1);
    ptr = (int*)malloc(size2);
    */

    /* Allocazione di N interi */
    int *ptrn, i;
    ptrn = (int*)malloc(N * sizeof(int));
    free(ptrn); /* Rilascio della memoria */

    return(EXIT_SUCCESS);
}

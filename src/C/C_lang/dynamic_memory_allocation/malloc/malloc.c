#include <stdio.h>
#include <stdlib.h>

#define N 10

/* L'allocazione dinamica della memoria consente l'allocazione di memoria sullo
heap, le funzioni principali con cui confrontarsi sono malloc(), calloc(), 
realloc() - generalmente ci si riferisce ad esse come le funzioni della
famiglia malloc() - e free().

Nota: L'allocazione dinamica della memoria (dynamic memory allocation) e' una
      tecnologia che dipende dal compilatore sul quale si deve lavorare, per 
      cui e' possibile che diverse architetture la trattino in maniera 
      differente. 

La funzione malloc() alloca un blocco di memoria sullo heap, il numero di byte
da allocare e' indicato dall'unico argomento 'size', in caso di esito negativo
sara' restituito NULL.

Chiamate successive non garantiscono continuita' nella memoria allocata, ovvero
le locazioni non saranno una di seguito all'altra, tuttavia vi sara' 
allineamento in accordo col tipo di dato del puntatore, nel caso specifico se
si utilizzasse un intero di 4 byte, gli indirizzi saranno sequenziali.

HEADER    : <stdlib.h>
PROTOTYPE : void *malloc(size_t size);
SEMANTICS : La funzione malloc alloca 'size' byte di memoria sullo heap.
RETURNS   : L'indirizzo della locazione di memoria piu' bassa del blocco di 
            memoria allocato in caso di successo, NULL in caso di errore.
--------------------------------------------------------------------------------
La massima grandezza del blocco di memoria allocabile mediante la funzione
malloc() dipende dall'architettura su cui si sta lavorando.
*/

int main(int argc, char *argv[]) {
    /* Allocazione di un intero */
    int *ptr;

    // Allocazione e verifica
    if ((ptr = (int *)malloc(sizeof(int))) == NULL) {
        fprintf(stderr, "Err. line:%d failed memory allocation\n", __LINE__-1);
        exit(EXIT_FAILURE);
    }

    /* Poichè la funzione malloc() ritorna (void*), ovvero l'indirizzo della 
    memoria allocata, bisogna specializzare la funzione stessa mediante un
    casting, nel caso specifico (int*). */

    *ptr = 1973;

    printf("Value of the integer allocated with malloc(): %d\n", *ptr);

    free(ptr);   /* Rilascio della memoria */

    /* Sono stati utilizzati 4 byte per un intero, la sizeof() rende il codice
    portabile.
    
    Le seguenti istruzioni sono del tutto equivalenti, il blocco di memoria 
    allocato sullo heap sara' sempre di 4 byte.

    int size1 = sizeof(int);
    int size2 = 4;
    
    ptr = malloc(size1);
    ptr = malloc(size2);
    */

    /* Allocazione di un blocco di N interi*/
    int *ptrn;
    
    if ((ptrn = (int *)malloc(N * sizeof(int))) == NULL) {
        fprintf(stderr, "Err. line:%d failed memory allocation\n", __LINE__-1);
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<N; i++) {
        ptrn[i] = i;
        printf("%d\n", ptrn[i]);
    }

    free(ptrn); /* Rilascio della memoria */

    // E' buona norma verificare se la memoria allocata risulta essere NULL
    int *p;
    p = malloc(sizeof(int));
    if (p != NULL)
        puts("pointer is ok");
    else
        puts("ops, pointer is not good");

    free(p);

    /* Variabili statiche e globali non permettono l'uso di malloc(), tuttavia
    la soluzione con le variabili statiche potrebbe essere la 
    non simultaneita' della dichiarazione con l'inizializzazione:

    static int *p;
    p = (int*)malloc(sizeof(int));

    Sarebbe errore utilizzarli nella medesima istruzione:
    static int *p  = (int*)malloc(sizeof(int));
    */

    return(EXIT_SUCCESS);
}

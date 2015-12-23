#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* La funzione calloc() alloca un blocco di memoria per un array sullo heap e, 
diversamente dalla malloc(), setta ciascun elemento a 0.

HEADER    : <stdlib.h>
PROTOTYPE : void *calloc(size_t num_elem, size_t size);
SEMANTICS : La funzione calloc() alloca memoria per un array di 'num_elem' 
            elementi, ciascuno di dimensione 'size'. Se 'num_elem' o 'size' e' 
            zero la funzione ritorna NULL.
RETURNS   : Un puntatore alla memoria allocata in caso di successo, NULL in caso
            di errore
--------------------------------------------------------------------------------
Poiche' alloca elementi contigui di memoria, inizialmente fu pensata proprio
per gli array, da notare tuttavia che richiede piu' tempo di una malloc().
*/

int main(void) {
    int i;
    const int tot_elem = 10;
    int *ptr;

    /* Si allocano 10 elementi da 4 byte ciascuno, per un totale di 40 byte, 
    ogni elemento dell'array e' settato a 0. */
    if ((ptr = calloc(tot_elem, sizeof(int))) == NULL) {
        fprintf(stderr, "Err.(line:%d) calloc()\n", __LINE__ - 1);
        exit(EXIT_FAILURE);
    }
    
    /* Si sarebbe potuto ottenere un risultato simile mediante malloc() e 
    memset():
    
    int *ptr = malloc(tot_elem * sizeof(int));  
    memset(ptr, 0, tot_elem * sizeof(int));     
    */

    for (i=0; i<tot_elem; i++)
        printf("%p = %d\n", (void *)&ptr[i], ptr[i]);

    /* Come si potra' ben notare anche in output, la relazione tra array e'
    puntatori e' molto molto stretta */

    exit(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 10;
    int *ptr = &n;

    /* size_t e' un unsigned int, ed e' utilizzato per fornire un tipo di dato
    sicuro per la gestione delle grandezze dei puntatori. */
    size_t ptr_size = sizeof(ptr);

    /* sizeof ritorna la grandezza di un tipo di dato, il suo valore di ritorno
    peraltro e' di tipo size_t; per la stampa i valori consigliabili sono, 
    nell'ordine: */

    printf("sizeof(ptr): %zu byte\n", ptr_size);
    printf("sizeof(ptr): %u byte\n", ptr_size);
    printf("sizeof(ptr): %lu byte\n", ptr_size);

    return(EXIT_SUCCESS);
}

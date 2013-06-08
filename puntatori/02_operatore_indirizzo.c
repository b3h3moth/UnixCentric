#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Poiche' una variabile puntatore puo' contenere l'indirizzo di una 
    locazione di memoria, si usa l'operatore indirizzo per assegnare 
    l'indirizzo di memoria di una variabile al puntatore stesso*/
    int n = 0;
    int *ptr = &n;
    
    /* L'operatore indirizzo ritorna l'indirizzo del suo operando.

    ptr e' una variabile puntatore ad un intero a cui si assegna l'indirizzo
    della variabile di tipo intero n; ora puntano alla stessa locazione di 
    memoria. */

    return(EXIT_SUCCESS);
}

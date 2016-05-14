#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE    10

/* Un array non puo' essere utilizzato come valore di ritorno di una funzione, 
piuttosto e' possibile far ritornare dalla funzione un puntatore a qualsiasi 
cosa, array compreso. */

int (*pf())[ARR_SIZE];

/* Lo scopo del programma e' di scrivere una funzione che ritorni un puntatore
a un array di ARR_SIZE elementi. */

int main(void) {

    int (*array)[ARR_SIZE] = pf();
    return(EXIT_SUCCESS);
}

// Alloca e inizializza a 0 ciascun elemento di un puntatore ad un array
int (*pf())[ARR_SIZE] {
    int (*parr)[ARR_SIZE] = calloc(ARR_SIZE, sizeof(int));
    return parr;
}

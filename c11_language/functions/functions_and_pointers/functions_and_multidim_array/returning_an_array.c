#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE    10

/* Un array non puo' essere utilizzato come valore di ritorno di una funzione, 
piuttosto e' possibile far ritornare dalla funzione un puntatore a qualsiasi 
cosa, array compreso. */

int (*pf())[ARR_SIZE];
void print(int (*p)[ARR_SIZE] );

/* Lo scopo del programma e' di scrivere una funzione che ritorni un puntatore
a un array di ARR_SIZE elementi, dopodiche' inizializzare ciascun elemento e
infine stampare ogni elemento del puntatore ad array. */

int main(void) {
    int (*array)[ARR_SIZE] = pf();

    for (int i=0; i<ARR_SIZE; i++)
        *(*array + i) = i*i;

    print(array);

    return(EXIT_SUCCESS);
}

/* Alloca e inizializza a 0 ciascun elemento di un puntatore ad un array, 
ritorna un puntatore all'area di memoria di un array di ARR_SIZE elementi. */
int (*pf())[ARR_SIZE] {
    int (*parr)[ARR_SIZE] = calloc(ARR_SIZE, sizeof(int));
    return parr;
}

// Stampa ciascun elemento di un puntatore ad array
void print(int (*p)[ARR_SIZE]) {
    int *ptmp;

    for (ptmp = *p; ptmp < (*p + ARR_SIZE); ptmp++)
        printf("%d\n", *ptmp);
}

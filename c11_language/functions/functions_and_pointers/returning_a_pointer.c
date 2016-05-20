#include <stdio.h>
#include <stdlib.h>

int *create_array(int size, int val);

/* Lo scopo del programma e' di scrivere una funzione che ritorni un puntatore.
La memoria sara' allocata mediante la funzione e sara' ritornato l'indirizzo
della memoria stessa. */

int main(void) {

    return(EXIT_SUCCESS);
}

/* La funzione crea un array di dimensione 'size', inizializzando ciascun 
elemento a 'val'. */
int *create_array(int size, int val) {
    int *array = malloc(sizeof(int) * size);

    for (int i=0; i<size; i++)
        *(array +i) = val;

    return array;
}

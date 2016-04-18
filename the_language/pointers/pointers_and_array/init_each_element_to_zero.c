#include <stdio.h>
#include <stdlib.h>

enum { SIZE = 10 };

// Lo scopo del programma e' l'inizializzazione di array mediante puntatori. 

int main(void) {
    double arr[SIZE];

    // Dal primo elemento all'ultimo
    for (double *ap = &arr[0]; ap < &arr[SIZE]; ap++) {
        *ap = 0;
        printf("%g, ", *ap);
    }

    // Dall'ultimo elemento al primo
    for (double *ap = &arr[SIZE]; ap > &arr[0]; ap--) {
        *ap = 1;
        printf("%g, ", *ap);
    }

    return(EXIT_SUCCESS);
}

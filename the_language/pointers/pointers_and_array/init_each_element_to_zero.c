#include <stdio.h>
#include <stdlib.h>

enum { SIZE = 10 };

/* Lo scopo del programma e' di inizializzare ciascun elemento dell'array a 0
mediante un puntatore. */

int main(void) {
    double arr[SIZE];

    for (double *ap = &arr[0]; ap < &arr[SIZE]; ap++) {
        *ap = 0;
        printf("%g, ", *ap);
    }

    return(EXIT_SUCCESS);
}

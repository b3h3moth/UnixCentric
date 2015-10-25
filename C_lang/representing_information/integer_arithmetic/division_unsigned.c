#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Si sta considerando la divisione di un numero di tipo unsigned per una
    potenza del 2, si intende dimostrare che se il left-shift equivale a
    moltiplicare per due, allora il right-shift corrisponde alla divisione
    per due */

    unsigned int num = 32768;

    printf("%d\n", num);

    // right-shift di 1, ovvero divisione per due
    for (int i=0; i<15; i++) {
        num = num >> 1;
        printf("%5d\n", num);
    }

    return(EXIT_SUCCESS);
}

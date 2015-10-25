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

    unsigned int number = 66880;
    unsigned int result = number >> 4;  // 66880/16

    printf("\n%d\n", number);
    printf("%d >> %d = %d\n", number, 4, result);
    printf("%d  * %d = %d\n", result, 16, result*16);

    /* Per una variabile 'var' di tipo unsigned, l'espressione:
    var >> n
    e' equivalente a x / 2^n, ovvero la potenza di due elevato alla 'n'
    */
    return(EXIT_SUCCESS);
}

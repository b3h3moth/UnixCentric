#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    /* Si sta considerando la divisione di un numero di tipo unsigned per una
    potenza del 2, si intende dimostrare che se il left-shift equivale a - 
    in alcuni casi - moltiplicare per una potenza del due, allora il 
    right-shift corrisponde alla divisione per una potenza del due */
    unsigned int num = 32768;

    printf("%d\n", num);

    // right-shift di 1, ovvero divisione per due
    for (int i=0; i<15; i++) {
        num = num >> 1;
        printf("%5d\n", num);
    }

    // Divisione di 'number' per una potenza del due 
    unsigned int number = 66880;
    unsigned int twopwr4 = pow(2, 4); // due alla quarta

    // Divisione di 'number' per 16, ovvero due alla quarta, 
    unsigned int division = number / twopwr4;
    // il right-shift porta al medesimo risultato
    unsigned int right_shift = number >> 4;  // 66880/16

    printf("\n%d\n", number);
    printf("%d  / %d = %d\n", number, 4, division);
    printf("%d >> %d = %d\n", number, 4, right_shift);

    /* Per una variabile 'var' di tipo unsigned, l'espressione:
    var >> n
    e' equivalente a x / 2^n, ovvero la potenza di due elevato alla 'n'
    */
    return(EXIT_SUCCESS);
}
/* Compilazione:
$ gcc   -std=c11 -Wall -pedantic -lm division_unsigned.c
$ clang -std=c11 -Wall -pedantic -lm division_unsigned.c
*/

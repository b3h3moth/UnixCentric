#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

/* Lo scopo del programma e' la realizzazione dell'algoritmo detto il crivello
di Eratostene per il calcolo di numeri primi. */

int main(void) {
    char sieve[SIZE];
    char *sp;
    int num;

    // setta ciascun elemento del crivello a 1
    for (sp = sieve; sp < SIZE; sp++) 
        *sp = 1;
    return(EXIT_SUCCESS);
}

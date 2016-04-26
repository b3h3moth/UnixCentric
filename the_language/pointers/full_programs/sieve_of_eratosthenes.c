#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

/* Lo scopo del programma e' la realizzazione dell'algoritmo detto il crivello
di Eratostene per il calcolo di numeri primi. */

int main(void) {
    char sieve[SIZE]; // Il crivello e' un array
    char *sp;
    int num;

    // Setta ciascun elemento del crivello a 1
    for (sp = sieve; sp < &sieve[SIZE]; sp++) 
        *sp = 1;

    // Processa i multipli del 3
    for (num = 3; num += 2; ) {
        sp = &sieve[0] + (num -3) / 2;

        if (sp >= &sieve[SIZE])
            break;

        while (sp += num, sp < &sieve[SIZE])
            *sp = 0;
    }
    return(EXIT_SUCCESS);
}

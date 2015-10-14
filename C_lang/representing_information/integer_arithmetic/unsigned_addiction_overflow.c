#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Lo scopo del programma e' di verificare la correttezza della somma
algebrica tra due valori unsigned in complemento a due, e di conseguenza
se il risultato della somma dovesse procurare un overflow. */

int unsigned_check_overflow(unsigned x, unsigned y);

int main(void) {
    unsigned val1 = 4294967294U; // unsigned int max number is 42949672945U
    unsigned val2 = 1;
    unsigned val3 = 2;

    printf("Max unsigned value: %u\n", UINT_MAX);
    if (unsigned_check_overflow(val1, val2))
        printf("%u + %u = %d\n", val1, val2, 1);

    if (unsigned_check_overflow(val1, val3) == 0)
        printf("%u + %u = %d (overflow)\n", val1, val3, 0);

    return(EXIT_SUCCESS);
}

// Returna 1 se gli argomenti possono essere sommati senza overlow
int unsigned_check_overflow(unsigned x, unsigned y) {
    unsigned sum = x + y;

    return (sum >= x);
}

#include <stdio.h>
#include <stdlib.h>

int arithmetic_shifts();

int main(void) {
    if ( arithmetic_shifts() )
        fputs("Machine with arithmetic shifts", stdout);
    else
        fputs("Machine with logical shifts", stdout);

    return(EXIT_SUCCESS);
}

int arithmetic_shifts() {
    // Imposta di ciascuno dei 32 bit a 1;
    int val = ~0;

    /* Se dopo lo shift di un bit a destra, 'val' sara' ancora uguale ad 1,
    allora sara' stato un shift aritmetico */
    return (val >> 1) == val;
}

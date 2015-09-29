#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Generalmente un 'int', su una macchina two's complement, e' dichiarato
    signed di default */
    int val1 = -1; // signed di default
    unsigned val2 = -1;

    printf("  signed val1: %d %x %u\n", val1, val1, val1);
    printf("unsigned val2: %d %x %u\n", val2, val2, val2);

    return(EXIT_SUCCESS);
}

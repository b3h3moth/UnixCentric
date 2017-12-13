#include <stdio.h>
#include <stdlib.h>

unsigned char is_zero(unsigned char val);
unsigned char is_equal(unsigned char x, unsigned char y);

/* La comparazione tra due 'unsigned char' per verificare se sono uguali,
mediante shifting, AND e XOR logico. */

int main(void) {
    unsigned char val1 = 252;
    unsigned char val2 = 254;

    if (is_equal(val1, val2))
        printf("Sono diversi\n");
    else
        printf("Sono uguali\n");

    return(EXIT_SUCCESS);
}

unsigned char is_zero(unsigned char val) {

    return( (val & (1<<7)) >> 7 |
            (val & (1<<6)) >> 6 |
            (val & (1<<5)) >> 5 |
            (val & (1<<4)) >> 4 |
            (val & (1<<3)) >> 3 |
            (val & (1<<2)) >> 2 |
            (val & (1<<1)) >> 1 | 
            (val & 1)) & 1;
}

unsigned char is_equal(unsigned char x, unsigned char y) {
    return(is_zero(x ^ y));
}

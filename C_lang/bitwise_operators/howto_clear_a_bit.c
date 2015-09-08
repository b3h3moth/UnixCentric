#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Azzerare un bit
    Azzeramento del bit numero 6 della variabile 'num' di tipo 'unsigned short'
    da 16 bit, mediante un AND e una maschera con il bit nella posizione 6 
    impostato a 0 e i restanti bit a 1. */
    unsigned short num1 = 0xEE; // 0000000011101110 &    (dec. 238)
    num1 &= ~0x0040;            // 1111111110111111 =    
                                // 0000000010101110      (dec. 174)
    printf("0x%X &= ~0x%X - 0x%X\n", 0xEE, 0x40, num1);

    // Oppure con uno shift-left, azzerando il bit 'i'esimo.
    unsigned short num2 = 0xEE;
    unsigned short i = 6;

    num2 &= ~(1 << i);

    printf("0x%X &= ~(%d << %d) - 0x%X\n", 0xEE, 1, i, num2);

    return(EXIT_SUCCESS);
}

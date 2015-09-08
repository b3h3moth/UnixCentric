#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Azzerare un bit
    Azzeramento del bit numero 6 della variabile 'num' di tipo 'unsigned short'
    da 16 bit, mediante una maschera con il bit nella posizione 6 impostato a 0
    e i restanti bit a 1. */
    unsigned short num = 0xEE; // 0000000011101110 &    (dec. 238)
    num &= ~0x0040;            // 1111111110111111 =    
                               // 0000000010101110      (dec. 174)
    printf("0x%x &= ~0x%x - 0x%x\n", 0xEE, 0x40, num);

    return(EXIT_SUCCESS);
}

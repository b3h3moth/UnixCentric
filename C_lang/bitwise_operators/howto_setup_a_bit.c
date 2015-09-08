#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Settare un bit
    Modifica del  bit numero 7 di una variabile di tipo 'unsigned short' da 16
    bit */
    unsigned short num1 = 0x0030;   // 0000000000110000 |
    num1 |= 0x40;                   // 0000000001000000 =
                                    // 0000000001110000
    printf("%d\n", num1);
    
    return(EXIT_SUCCESS);
}

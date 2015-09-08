#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Settare un bit
    Modifica del  bit numero 7 di una variabile di tipo 'unsigned short' da 16
    bit */
    unsigned short num1 = 0x0030;   // 0000000000110000 |   (dec. 48)
    num1 |= 0x0040;                 // 0000000001000000 =   (dec. 64)
                                    // 0000000001110000     (dec. 112)
    printf("0x00%x |= 0x00%x = 0x00%x\n", 0x30, 0x40, num1);
    
    return(EXIT_SUCCESS);
}

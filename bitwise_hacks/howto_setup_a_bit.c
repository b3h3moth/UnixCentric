#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Settare un bit
    Modifica del bit numero 6 di una variabile di tipo 'unsigned short' da 16
    bit, mediante un OR e una maschera con il bit nella posizione 6 impostato a
    1 e i restanti bit a 0. */
    unsigned short num1 = 0x0030; // 0000000000110000 |   (dec. 48)
    num1 |= 0x0040;               // 0000000001000000 =   (dec. 64)
                                  // 0000000001110000     (dec. 112)
    printf("0x%x |= 0x%x - 0x%x\n", 0x30, 0x40, num1);
   
    // Oppure con uno shift-left
    unsigned short num2 = 0x0030; 
    unsigned short i = 6;

    num2 |= 1 << i;
    
    printf("%#x |= %d << %d - %#x\n", 0x00, 1, i, num2);

    return(EXIT_SUCCESS);
}

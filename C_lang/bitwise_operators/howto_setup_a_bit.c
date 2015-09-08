#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Settare un bit (OR, |)
    Modifica del bit numero 7 di una variabile di tipo 'unsigned short' da 16
    bit */
    unsigned short num1 = 0x0030; // 0000000000110000 |   (dec. 48)
    num1 |= 0x0040;               // 0000000001000000 =   (dec. 64)
                                  // 0000000001110000     (dec. 112)
    printf("0x%x |= 0x%x - 0x%x\n", 0x30, 0x40, num1);
   
    // Oppure con uno shift-left, si ottiene il medesimo risultato
    unsigned short num2 = 0x0000; 
    unsigned short i = 4;

    num2 |= 7 << i;
    
    printf("num |= %d << %d - 0x%x\n", 7, i, num2);

    return(EXIT_SUCCESS);
}

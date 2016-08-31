#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Recuperare un valore da un campo di bit
    In questo caso si recuperano i 3 bit meno significativi, ovvero 0,1,2 */
    unsigned int num1 = 0xAF; // 10101111

    // num2 reecupera i 3 bit meno significativi e vale 00000111, 0x07
    unsigned int num2 = num1 & 0x07;

    // num3 recupera i bit 4,5,6 mediante shift, e vale 00000010, 0x02
    unsigned int num3 = (num1 >> 4) & 0x07;
 
    printf("num1:%#x num2:%#x num3:%#x\n", num1, num2, num3);

    return(EXIT_SUCCESS);
}

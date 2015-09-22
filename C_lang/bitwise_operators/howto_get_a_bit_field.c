#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Recuperare un valore da un campo di bit
    In questo caso si recuperano i 3 bit meno significativi, ovvero 0,1,2 */
    unsigned int num1 = 0xAF; // 10101111
    unsigned int num2 = num1 & 0x7;
    // num2 reecupera i 3 bit meso significativi e vale 00000111, 0x7

    printf("num1:0x%X num2:0x%X\n", num1, num2);

    return(EXIT_SUCCESS);
}

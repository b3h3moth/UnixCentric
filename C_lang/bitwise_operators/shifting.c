#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* In tutti e 3 i casi ci sara' un messaggio di warning del compilatore,
    inoltre ciascun risultato sara' 0x00. */
    int      num1 = 0xFEDCBA98  << 32; // 32 bit
    int      num2 = 0xFEDCBA98  >> 36; // 32 bit
    unsigned num3 = 0xFEDCBA98  >> 40; // 32 bit

    printf("0x%x\n", num1);
    printf("0x%x\n", num2);
    printf("0x%x\n", num3);

    return(EXIT_SUCCESS);
}

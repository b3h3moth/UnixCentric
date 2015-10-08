#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* In tutti e 3 i casi ci sara' un messaggio di warning del compilatore,
    inoltre ciascun risultato sara' 0x00. Il motivo e' la lunghezza della word
    a 32 bit. */
    int      num1 = 0xFEDCBA98 << 32; // 32 bit
    int      num2 = 0xFEDCBA98 >> 36; // 32 bit
    unsigned num3 = 0xFEDCBA98 >> 40; // 32 bit

    /* In entrambi i casi '1', viene spostato sul bit piu' significativo,
    per cui sara' 10000000 00000000 00000000 00000000 */
    int      num4 = 0x00000001 << 31; // 32 bit
    unsigned num5 = 0x00000001 << 31; // 32 bit

    /* I bit vengono riempiti con degli '1' se il tipo di dato e' 'int', con
    degli '0' se il tipo di dato e' 'unsigned' */
    num4 >>= 3; // 11110000 00000000 00000000 00000000
    num5 >>= 3; // 00010000 00000000 00000000 00000000

    printf("%#x\n", num1);
    printf("%#x\n", num2);
    printf("%#x\n", num3);
    printf("%#x %10d\n", num4, num4);
    printf("%#x %10d\n", num5, num5);

    return(EXIT_SUCCESS);
}

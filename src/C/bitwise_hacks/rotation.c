#include <stdio.h>
#include <stdlib.h>

/* La funzione right_rotation() ruota 'n' bit verso destra, portandoli verso
i bit più significativi */
unsigned char right_rotation(unsigned char val, int n) {
    return (val >> n) | (val << 8 - n);
}

/* La funzione left_rotation() ruota 'n' bit verso sinistra, portandoli verso
i bit meno significativi */
unsigned char left_rotation(unsigned char val, int n) {
    return (val << n) | (val >> 8 - n);
}

int main(void) {
    unsigned char val1 = 0xAF;   /* 10101111 */
    unsigned char valr = right_rotation(val1, 4); /* 4 bit right rotation */
    unsigned char vall = left_rotation(val1, 3);  /* 3 bit left rotation */

    printf("Before : %d (0x%X)\nAfter  : %d (0x%X)\n", 
            val1, val1, valr, valr);

    printf("Before : %d (0x%X)\nAfter  : %d (0x%X)\n", 
            val1, val1, vall, vall);

    /* 
    Right rotation
    Before : 10101111 (0xAF, 175)
    After  : 11111010 (0xFA, 250)
    10101111 >> 4 = 00001010 
    10101111 << 4 = 11110000
    00001010 | 11110000 = 11111010

    Left rotation
    Before : 10101111 (0xAF, 175)
    After  : 01111101 (0xFA, 250)
    10101111 << 3 = 01111000
    10101111 >> 5 = 00000101
    01111000 | 00000101 = 01111101
    */

    return(EXIT_SUCCESS);
}

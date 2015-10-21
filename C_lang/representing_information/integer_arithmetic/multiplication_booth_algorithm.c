#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
signed short multiplication_8bit(signed char m, signed char r);

int main(void) {
    return(EXIT_SUCCESS);
}

/* Booth algorithm per la moltiplicazione numeri 
in two's complement con word-size di 8-bit */
signed short multiplication_8bit(signed char m, signed char r) {
    signed int A, S, P;
    unsigned char i;

    A = m << 9;
    S = (-m) << 9;
    P (r & 0xFF) << 1;

    for (i=0; i<CHAR_BIT; i++) {
        switch ( P & 3) {
            case 1:     // 01
                p += A;
                break;
            case 2:     // 10
                p += S;
                break;
            default:    // 11 oppure 00
                break;
        }
        p >>= 1;
    }
    return P >> 1;
}

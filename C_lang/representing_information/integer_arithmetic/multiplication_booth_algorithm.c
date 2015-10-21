#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

signed short multiplication_8bit(signed char m, signed char r);

int main(void) {
    signed int val1 = 7;
    signed int val2 = 8;

    signed short result = multiplication_8bit(val1, val2);

    printf("%d * %d = %d\n", val1, val2, result);

    return(EXIT_SUCCESS);
}

/* Booth algorithm per la moltiplicazione numeri 
in two's complement con word-size di 8-bit */
signed short multiplication_8bit(signed char m, signed char r) {
    signed int A, S, P;
    unsigned char i;

    A = m << 9;
    S = (-m) << 9;
    P = (r & 0xFF) << 1;

    for (i=0; i<CHAR_BIT; i++) {
        switch ( P & 3) {
            case 1:     // 01
                P += A;
                break;
            case 2:     // 10
                P += S;
                break;
            default:    // 11 oppure 00
                break;
        }
        P >>= 1;
    }
    return P >> 1;
}

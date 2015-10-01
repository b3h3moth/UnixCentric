#include <stdio.h>
#include <stdlib.h>
#include "show_bytes.h"

int main(void) {
    /* La conversione da "two's complement", ovvero numero negativi, ad un tipo
    di maggior grandezza riempira' col bit piu' significativo i bit iniziali
    (sign extension) */

    short val1 = -12345;        // short 2 byte
    unsigned short val2 = val1; // unsigned short 2 byte
    int val3 = val1;            // int 4 byte
    unsigned val4 = val2;       // unsigned int 4 byte
    long long val5 = val1;      // long long 8 byte

    printf("(val1=%d)\t", val1);
    show_bytes((byte_pointer) &val1, sizeof(short));

    printf("(val2=%d)\t", val2);
    show_bytes((byte_pointer) &val2, sizeof(unsigned short));

    printf("(val3=%d)\t", val3);
    show_bytes((byte_pointer) &val3, sizeof(int));

    printf("(val4=%d)\t", val4);
    show_bytes((byte_pointer) &val4, sizeof(unsigned));

    printf("(val5=%lld)\t", val5);
    show_bytes((byte_pointer) &val5, sizeof(long long));

    return(EXIT_SUCCESS);
}

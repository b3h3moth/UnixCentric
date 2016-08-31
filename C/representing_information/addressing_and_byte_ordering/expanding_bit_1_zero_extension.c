#include <stdio.h>
#include <stdlib.h>
#include "show_bytes.h"

int main(void) {
    /* La conversione dal tipo 'unsigned' ad un tipo di maggior grandezza
    riempira' con diversi zero i bit iniziali (zero extension) */

    unsigned short val1 = 12345;    // unsigned short 2 byte
    unsigned val2 = val1;           // unsigned 4 byte
    unsigned long long val3 = val1; // unsigned long long 8 byte

    printf("(val1=%d)\t", val1);
    show_bytes((byte_pointer) &val1, sizeof(unsigned short));

    printf("(val2=%d)\t", val2);
    show_bytes((byte_pointer) &val2, sizeof(unsigned));

    printf("(val3=%lld)\t", val3);
    show_bytes((byte_pointer) &val3, sizeof(unsigned long long));

    return(EXIT_SUCCESS);
}

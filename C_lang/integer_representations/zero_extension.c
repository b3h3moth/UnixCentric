#include <stdio.h>
#include <stdlib.h>
#include "show_bytes.h"

int main(void) {
    /* La conversione dal tipo 'unsigned' ad un tipo di maggior grandezza
    riempira' con diversi zero i bit iniziali (zero extension) */
    short val1 = 12345;     // short 2 byte
    int val2 = val1;        // int 4 byte
    long long val3 = val1;  // long long 8 byte

    printf("(val1=%d)\t", val1);
    show_bytes((byte_pointer) &val1, sizeof(unsigned short));

    printf("(val2=%d)\t", val2);
    show_bytes((byte_pointer) &val2, sizeof(int));

    printf("(val3=%lld)\t", val3);
    show_bytes((byte_pointer) &val3, sizeof(long long));

    return(EXIT_SUCCESS);
}

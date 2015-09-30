#include <stdio.h>
#include <stdlib.h>
#include "show_bytes.h"

int main(void) {
    /* La conversione dal tipo 'unsigned' ad un tipo di maggior grandezza
    riempira' con diversi zero i bit iniziali (zero extension) */
    unsigned short us_val1 = 12345;
    int i_val1 = us_val1;

    printf("(unsigned short=%d)\t", us_val1);
    show_bytes((byte_pointer) &us_val1, sizeof(unsigned short));

    printf("(int=%d)\t", i_val1);
    show_bytes((byte_pointer) &i_val1, sizeof(int));

    return(EXIT_SUCCESS);
}

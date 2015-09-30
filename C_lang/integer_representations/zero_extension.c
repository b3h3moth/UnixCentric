#include <stdio.h>
#include <stdlib.h>
#include "show_bytes.h"

int main(void) {
    /* La conversione dal tipo 'unsigned' ad un tipo di maggior grandezza
    riempira' con diversi zero i bit iniziali (zero extension) */
    unsigned short val = 12345;
    int cval = val;
    return(EXIT_SUCCESS);
}

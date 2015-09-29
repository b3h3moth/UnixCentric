#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Generalmente un 'int', su una macchina two's complement, e' dichiarato
    signed di default */

    int val1 = -1; // signed di default

    // Aggiungendo tuttavia 'U' o 'u' al suffisso si crea invece un 'unsigned'
    int val2 = 1234u;
    int val3 = 0x5678U;

    return(EXIT_SUCCESS);
}

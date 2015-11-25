#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned char uch = 0xFF;
    char ch = 0xFF;

    // Which is the result? Are you sure?
    int val = (uch == ch);

    printf("Result is: %d\n", val);

    /* Nella rappresentazione in complemento a due il range di numeri 
    rapppresentabili dell'unsigned char va da 0 a 255, mentre per il 
    signed char va da -128 a + 127, per cui il risultato della conversione
    ad int e':

    uch = 0xFF = 255 = 0x000000FF
     ch = 0xFF =  -1 = 0xFFFFFFFF

    Il risultato naturalmente e' false, 1. */

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned char uch = 0xFF;
    char ch = 0xFF;

    // Which is the result? Are you sure?
    int val = (uch == ch);

    printf("Result is: %d\n", val);

    /* Nella rappresentazione in complemento a due del tipo di dato 
    'unsigned char' e' strutturato mediante un intervallo di valori compreso 
    tra 0 a 255, mentre per il tipo di dato 'signed char' l'intervallo e' 
    compreso tra -128 e 127. 
    
    Il risultato della promozione di entrambi i tipi su citati in 'int' e'
    chiaramente falso '0', poiche':

    uch = 0xFF = 255 = 0x000000FF
     ch = 0xFF =  -1 = 0xFFFFFFFF
    */

    return(EXIT_SUCCESS);
}

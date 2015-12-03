#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Il tipo di dato 'char' e' definito di default come un 'unsigned char'
    char uch = 0xFF;
    signed char ch = 0xFF;

    // Which is the result? Are you sure?
    int val = (uch == ch);

    printf("Result is: %d\n", val);

    printf("(unsigned) char 0x%08x\n", uch);
    printf("    signed char 0x%08x\n", ch);

    /* Nella rappresentazione in complemento a due il tipo di dato 
    'unsigned char' gode di un intervallo di valori compreso tra 0 a 255, 
    mentre il tipo di dato 'signed char' o 'char' ha un intervallo
    compreso tra -128 e 127. 
    
    Il risultato della promozione di entrambi i tipi su citati in 'int' e'
    chiaramente falso '0', poiche':

    uch = 0xFF = 255 = 0x000000FF
     ch = 0xFF =  -1 = 0xFFFFFFFF
    */

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Convertire un numero negativo in un 'unsigned' potrebbe dare come
    risultato 0, per quanto riguarda le conversioni ci si deve sempre basare
    sulla rappresentazione dei singoli bit. */

    /* 'short int' oppure semplicemente 'short' e' un tipo di dato da 2 byte, 
    ovvero 16 bit. */
    short val = -12345;
    unsigned short uval = (unsigned short) val;

    printf("val=%d\nuval=%d\n", val, uval);

    return(EXIT_SUCCESS);
}

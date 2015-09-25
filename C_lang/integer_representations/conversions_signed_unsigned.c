#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Convertire un numero negativo in un 'unsigned' potrebbe dare come
    risultato 0, tuttavia per quanto riguarda le conversioni si deve sempre
    considerare la rappresentazione dei singoli bit */

    /* 'short int' oppure semplicemente 'short' e' un tipo di dato da 2 byte, 
    ovvero 16 bit. */
    short val = -12345;

    /* Casting di un numero negativo di tipo 'short' in un 'unsigned short',
    entrambi di 2 byte ma con valori minimi e massimi differenti */
    unsigned short uval = (unsigned short) val;

    /* Il risultato sara':

    val = -12345 (binario: 1110001111110011)
    uval = 53191 (binario: 1110001111110011)
    
    Il casting da short [int] ad 'unsigned short' cambia il valore numerico 
    lasciando immutata la raoppresentazione in complemento a due dei bit.
    */

    printf("val=%d\nuval=%d\n", val, uval);

    return(EXIT_SUCCESS);
}

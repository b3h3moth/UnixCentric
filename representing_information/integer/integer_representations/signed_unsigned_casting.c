#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    /* Casting short [int], unsigned short [int]
    Convertire un numero negativo in un 'unsigned' potrebbe dare come
    risultato 0, tuttavia per quanto riguarda le conversioni si deve sempre
    considerare la rappresentazione dei singoli bit */

    /* 'short int' oppure semplicemente 'short' e' un tipo di dato da 2 byte, 
    ovvero 16 bit. */
    short val1 = -12345;

    /* Casting di un numero negativo di tipo 'short' in un 'unsigned short',
    entrambi di 2 byte ma con valori minimi e massimi differenti */
    unsigned short cast_val1 = (unsigned short) val1;

    /* Il risultato sara':

    val = -12345 (binario: 1110001111110011)
    uval = 53191 (binario: 1110001111110011)
    
    Il casting da short [int] ad 'unsigned short' modifica il valore numerico 
    lasciando immutata la rappresentazione in complemento a due dei bit.
    */

    printf("val1=%d\tcast_val1=%d\n", val1, cast_val1);

    // Casting unsigned [int], int 
    unsigned val2 = 4294967295U;    // UINT_MAX
    int cast_val2 = (int) val2;

    /* Su una macchina con una word a 32 bit, il valore massimo per il tipo
    'unsigned' e' 4294967295U (0xFFFFFFFF) e il cast a 'int' in complemento a
    due risulta essere -1, ossia (0xFFFFFFFF), per cui anche in questo caso 
    vi e' una modifica al valore numerico ma i bit restano i medesimi */

    printf("val2=%u\tcast_val2=%d\n", val2, cast_val2);

    /* Per concludere, la regola vuole che il casting di numeri 'signed' e
    'unsigned' con la stessa word size, il valore numerico cambi ma la
    rappresentazione interna dei bit resti immutata */

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Generalmente un 'int', su una macchina two's complement, e' dichiarato
    signed di default */

    int val1 = -1; // signed di default

    // Aggiungendo tuttavia 'U' o 'u' al suffisso si crea invece un 'unsigned'
    int val2 = 1234u;
    int val3 = 0x5678U;

    printf("signed:%d, unsigned:%u, unsigned:%#x\n", val1, val2, val3);

    /* Se in una operazione vi sono due operandi, uno dei quali 'signed' e
    l'altro 'unsigned', il C eseguira' implicitamente un cast sull'operando
    'signed' rendendolo 'unsigned', dopodiche' l'operazione sara' eseguita
    come fosse su numeri 'unsigned.
    
    Tale comportamento, in accoppiata con gli operatori relazionali >,<, puo'
    portare a risultati non propriamente prevedibili. */

    int sval1 = -1;
    unsigned uval2 = 0u;

    /* Poiche' uno dei due operandi e' 'unsigned' sara' eseguito un casting
    sull'operando 'signed', che convertito in 'unsigned' assumera' il valore di
    4294967295, pertanto il risultato del confronto sara' false */

    if (sval1 < uval2)
        printf("true");
    else
        printf("%u < %d (False)", (unsigned)sval1, uval2);

    return(EXIT_SUCCESS);
}

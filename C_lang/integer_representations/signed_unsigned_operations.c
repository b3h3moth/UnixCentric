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

    // Test 1
    int sval1 = -1;
    unsigned uval1 = 0u;

    /* Poiche' uno dei due operandi e' 'unsigned' sara' eseguito un casting
    sull'operando 'signed', che convertito in 'unsigned' assumera' il valore di
    4294967295, pertanto il risultato del confronto sara' false */

    if (sval1 < uval1)
        printf("true:1\n");
    else
        printf("%u < %u (false:0)\n", (unsigned)sval1, uval1);

    // Test 2
    int sval2 = -2147483647-1;
    unsigned uval2 = 2147483647U;

    if (uval2 > sval2)
        printf("true:1\n");
    else
        printf("%u > %u (false:0)\n", uval2, (unsigned)sval2);

    // Test 3
    int sval3 = 2147483647;
    int uval3 = (int) 2147483648U;

    if (sval3 > uval3)
        printf("%d > %d (true:1)\n", sval3, uval3);
    else
        printf("false:0\n");

    return(EXIT_SUCCESS);
}

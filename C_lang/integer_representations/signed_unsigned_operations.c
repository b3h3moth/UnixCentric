#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Generalmente un 'int', su una macchina two's complement, e' dichiarato
    signed di default */

    int val1 = -1; // signed di default

    // Aggiungendo tuttavia 'U' o 'u' al suffisso si crea invece un 'unsigned'
    int val2 = 1234u;
    int val3 = 0x5678U;

    /* Se in una operazione vi sono due operandi, uno dei quali 'signed' e
    l'altro 'unsigned', il C eseguira' implicitamente un cast sull'operando
    'signed' rendendolo 'unsigned', dopodiche' l'operazione sara' eseguita
    come fosse su numeri 'unsigned' */

    return(EXIT_SUCCESS);
}

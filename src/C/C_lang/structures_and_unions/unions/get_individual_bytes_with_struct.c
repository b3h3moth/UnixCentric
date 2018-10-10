#include <stdio.h>
#include <stdlib.h>

/* Si intende stampare sullo stdout ciascun byte di un 'unsigned int', tale
rappresentazione sara' possibile grazie alla 'union' che consentira' di
visualizzare un byte per volta e di accertare peraltro anche l'ordinamento
dei byte stessi in memoria. 

La visualizzazione di ciascun byte e' affidata a una struct i cui membri sono
quattro variabili di tipo char, ovvero un byte per carattere. */

union unsigned_inspect {
    unsigned int val;
    struct { char c0, c1, c2, c3; } byte;
};

typedef union unsigned_inspect unsigned_inspect;

unsigned_inspect datatest = { .val = 0xABCDEF12, };

int main(void) {
    printf("Byte representation of unsigned value: '%#x'\n", datatest.val);
    
    printf("byte[0]: %#x\n", datatest.byte.c0);
    printf("byte[1]: %#x\n", datatest.byte.c1);
    printf("byte[2]: %#x\n", datatest.byte.c2);
    printf("byte[3]: %#x\n", datatest.byte.c3);

    return(EXIT_SUCCESS);
}

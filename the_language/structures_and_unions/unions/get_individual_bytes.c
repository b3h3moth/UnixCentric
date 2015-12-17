#include <stdio.h>
#include <stdlib.h>

/* Si intende stampare sullo stdout ciascun byte di un 'unsigned', tale
rappresentazione sara' possibile grazie alla 'union' che consentira' di
visualizzare un byte per volta e quindi di accertare anche l'ordinamento
dei byte stessi della macchina. */

typedef union unsigned_inspect unsigned_inspect;

union unsigned_inspect {
    unsigned val;
    unsigned char bytes[sizeof(unsigned)];
};

unsigned_inspect datatest = { .val = 0x12ABCDEF, };

int main(void) {
    printf("Byte representation of unsigned value: '%#x'\n", datatest.val);

    // Each byte will be printed on the stdout separately
    for (size_t i = 0; i<sizeof(datatest.bytes); ++i)
        printf("byte[%zu]: %#x\n", i, datatest.bytes[i]);

    return(EXIT_SUCCESS);
}

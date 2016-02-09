#include <stdio.h>
#include <stdlib.h>

/* Si intende stampare sullo stdout ciascun byte di un 'unsigned int', tale
rappresentazione sara' possibile grazie alla 'union' che consentira' di
visualizzare un byte per volta e di accertare peraltro anche l'ordinamento
dei byte stessi in memoria. 

La visualizzazione di ciascun byte e' affidata a un array di 'unsigned int'
elementi, ovvero 4.*/

union unsigned_inspect {
    unsigned int val;
    unsigned char bytes[sizeof(unsigned int)];
};

typedef union unsigned_inspect unsigned_inspect;

unsigned_inspect datatest = { .val = 0x12ABCDEF, };

int main(void) {
    printf("Byte representation of unsigned int value: '%#x'\n", datatest.val);

    // Each byte will be printed on the stdout separately
    for (size_t i = 0; i<sizeof(datatest.bytes); ++i)
        printf("byte[%zu]: %#x\n", i, datatest.bytes[i]);

    return(EXIT_SUCCESS);
}

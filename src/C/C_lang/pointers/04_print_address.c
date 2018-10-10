#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int num = 123456789;
    unsigned int *ptr = &num;

    /* Per la stampa degli indirizzi e' possibile adoperare lo specificatore 
    '%p' della printf(), che fornira' un indirizzo preceduto da 0x. Associato 
    allo specificatore '%p' e' consigliabile utilizzare un casting con un 
    puntatore a void, cosi' facendo ne guadagnera' la portabilita'. */

    printf(" num [address: %p] [value: %d]\n", (void *)&num, num);
    
    printf("*ptr [address: %p] [value: %p]\n", (void *)&ptr, (void *)ptr);

    /* Altri specificatori sono %x e %X che consentono la stampa in esadecimale
    con lettere minuscole e maiuscole rispettivamente, essi tuttavia non 
    prevedeno di default l'utilizzo in stampa di 0x, per evitare di inserirlo
    manualmente e' possibile aggiungere '#', nella forma %#x. 

    Tabella riassuntiva degli specificatori
    ---------------------------------------
    %p  - restituisce un indirizzo in esadecimale maiuscolo, preceduto da 0x
    %x  - restituisce un indirizzo in esadecimale minuscolo
    %X  - restituisce un indirizzo in esadecimale minuscolo
    %#x - restituisce un indirizzo in esadecimale minuscolo, preceduto da 0x
    %#X - restituisce un indirizzo in esadecimale minuscolo, preceduto da 0x
    %o  - restituisce un indirizzo in ottale
    */

    printf("value of 'num' in (hex): %x\n", num);
    printf("value of 'num' in (hex): %X\n", num);
    printf("value of 'num' in (hex): %#x\n", num);
    printf("value of 'num' in (hex): %#X\n", num);
    printf("value of 'num' in (oct): %o\n", num);

    return(EXIT_SUCCESS);
}

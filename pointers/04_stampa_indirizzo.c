#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0;
    int *ptr = &n;

    /* Per la stampa degli indirizzi e' consigliabile adoperare lo specificatore
    %p, che fornira' un indirizzo preceduto da 0x; con %p e' consigliabile
    utilizzare il cast del puntatore ad un puntatore a void, questo per rendere
    il codice eseguibile su diverse architetture. */

    printf("Address of n: %p - Value %d\n", (void *)&n, n);
    
    printf("Address of ptr: %p - Value %p\n", (void *)&ptr, (void *)ptr);

    /* Altri specificatori sono %x per l'esadecimale senza 0x iniziale e %o
    per l'ottale.

    Tabella riassuntiva degli specificatori
    ---------------------------------------
    %p - restituisce un indirizzo in esadecimale maiuscolo, preceduto da 0x
    %x - restituisce un indirizzo in esadecimale minuscolo
    %o - restituisce un indirizzo in ottale
    */
    printf("Address of n (hex): %x\n", &n);
    printf("Address of n (oct): %o\n", &n);

    return(EXIT_SUCCESS);
}

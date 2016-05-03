#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE 10

/* Lo scopo del sorgente e' di simulare la funzione calloc() mediante l'ausilio
delle funzioni calloc() e memset(). Per simulazione s'intende l'ottenimento del
medesimo risultato finale e non la realizzazione interna del programma.  */

int main(void) {
    int *pval = malloc(BYTE * sizeof(int));
    memset(pval, 0, BYTE * sizeof(int));

    // Setto i primi cinque byte a 1
    *pval = *(pval + 1) = *(pval + 2) = *(pval + 3) = *(pval + 4) = 1;

    /* La stampa di ciascun elemento mostra i primi 5 elementi impostati ad 1
    e gli altri cinque settati a zero mediante memset() */
    for (int i=0; i<BYTE; i++)
        printf("%d\n", *(pval + i));

    return(EXIT_SUCCESS);
}

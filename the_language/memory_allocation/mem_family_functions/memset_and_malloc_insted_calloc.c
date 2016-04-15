#include <stdio.h>
#include <stdlib.h>

#define BYTE 10

/* Lo scopo del sorgente e' di simulare la funzione calloc() mediante l'ausilio
delle funzioni calloc() e memset(). Per simulazione s'intende l'ottenimento del
medesimo risultato finale e non la realizzazione interna del programma.  */

int main(void) {
    int *pval = malloc(BYTE *sizeof(int));
    memset(pval, 0, BYTE)

    printf("%d\n", sizeof(*pval));
    return(EXIT_SUCCESS);
}

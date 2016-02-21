#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Lo scopo del programma e' redirigere lo stream output verso un file mediante
la funzione freopen(), dopodiche' scrivere nel file stesso una stringa che 
identifichi la data esatta della scrittura della stringa stessa. 
Tale esempio puo' essere un buon punto di partenza per la realizzazione di 
routine di debugging e/o testing. */

int main(void) {
    time_c sec;
    char fname[] = "data.txt";

    fputs("Before freopen()", stdout);

    if (freopen(fname, "w", stdout) == NULL) {
        fprintf(stderr, "Unable to redirect stdout stream.\n");
    } else 
        printf("Line executed at %.24s\n", ctime(&sec));
    
    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Assegnando ad una variabile di tipo 'unsigned long' il valore '-1', ciascun
bit sara' impostato a 1, per cui essendo 'unsigned long' di 4 byte come 'int'
si otterra' il valore massimo 'UINT_MAX' 'unsigned int'. Dovrebbe funzionare 
su quasi tutte le architetture. */

int main(void) {
    unsigned long ulval = -1;

    if (ulval == UINT_MAX)
        printf("%lu = %u\n", ulval, UINT_MAX);
    else
        fputs("Err.\n", stdout);

    return(EXIT_SUCCESS);
}

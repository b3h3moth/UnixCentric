#include <stdio.h>
#include <stdlib.h>

// Lo scopo del programma e' la realizzazione di un puntatore a puntatore

int main(void) {
    int val = 100;
    /* La variabile puntatore 'ptr' contiene l'indirizzo di memoria della 
    variabile intera 'val' */
    int *ptr = &val;
    /* La variabile puntatore a puntatore 'pptr' contiene l'indirizzo della
    variabile puntatore 'ptr', che a sua volta punta a 'val', per cui 
    pptr punta a 'val'. */
    int **pptr = &ptr;

    return(EXIT_SUCCESS);
}

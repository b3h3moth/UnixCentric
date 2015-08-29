#include <stdio.h>
#include <stdlib.h>

#define NUM_PAGES 2
#define NUM_ROWS 3
#define NUM_COLS 4

/* Un array con piu' di due dimensioni puo' essere visto come  una sorta di
pila di tabelle o pagine una sopra l'altra; la prima dimensione indica la 
pagina la seconda e la terza sono le righe e le colonne. */

int main(void) {

    /* Array multidimensionale, tridimensionale
    Una pila di 3 tabelle/pagine, ciscuna di esse formata da 3 righe e 4 
    colonne, in totale conterra' 24 elementi. */
    int array[NUM_PAGES][NUM_ROWS][NUM_COLS];



    return(EXIT_SUCCESS);
}

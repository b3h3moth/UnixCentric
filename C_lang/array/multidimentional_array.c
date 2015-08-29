#include <stdio.h>
#include <stdlib.h>

#define NUM_PAGES 3
#define NUM_ROWS 3
#define NUM_COLS 4

/* Un array con piu' di due dimensioni puo' essere visto come  una sorta di
pila di tabelle o pagine una sopra l'altra; la prima dimensione indica la 
pagina la seconda e la terza sono le righe e le colonne. */

int main(void) {

    /* Array multidimensionale, tridimensionale
    Una pila di 3 tabelle/pagine, ciscuna di esse formata da 3 righe e 4 
    colonne, in totale conterra' 24 elementi. */
    int array[NUM_PAGES][NUM_ROWS][NUM_COLS] = {
        
        { // Pagina 1
            {1, 2, 3, 4},    // Riga 1
            {5, 6, 7, 8},    // Riga 2
            {9, 10, 11, 12}, // Riga 3
        },
        
        { // Pagina 2
            {13, 14}, // Riga 1 - i restanti elementi a 0
            {15, 16}, // Riga 2 - i restanti elementi a 0
                      // Riga 3 tutto a 0 di default
        },

         /* Pagina 3, inizializzatore designato per gli elementi della prima e
         della terza riga, dopodiche'tutto a 0 di default */
         [2][0][0] = 17, // Riga 1
         [2][0][1] = 18, 
         [2][0][2] = 19,
         [2][2][3] = 20, 
         [2][2][0] = 21, // Riga 3
         [2][2][1] = 22,
         [2][2][2] = 23,
         [2][2][3] = 24,
    };

    for (int i=0; i<NUM_PAGES; i++) { // Indice pagina
        printf("PAGE %d:\n", i);
        for (int y=0; y<NUM_ROWS; y++) { // Indice riga
            for (int j=0; j<NUM_COLS; j++) { // Indice colonna
                printf("%2d, ", array[i][y][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return(EXIT_SUCCESS);
}

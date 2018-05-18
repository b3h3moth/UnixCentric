#include <stdio.h>
#include <stdlib.h>

#define ROWS    2
#define COLS    3

int main(void) {

    // Array bidimensionale e' sinonimo di matrice
    // Dichiarazione di una matrice di tipo intero
    // Inizializzazione a 0 di ciascun elemento
    int matrix_a[ROWS][COLS] = { {0} };

    // Inizializzazione contestualmente alla dichiarazione
    // Valgono comunque le regole per i vettori
    int matrix_b[ROWS][COLS] = { {10, 20, 30},
                                 {40, 50, 60} };

    /* Calcolo dell'occupazione di memoria */
    int n_bytes = sizeof(matrix_a);

    /* Calcolo del numero degli elementi */
    int n_elem = n_bytes / sizeof(int);

    /* Calcolo del numero di colonne */
    int n_rows = sizeof(matrix_a[0]) / sizeof(int);

    /* Calcolo del numero di righe */
    int n_cols = n_elem / n_cols

    // Accesso agli elementi
    int num = matrix_b[0][1]; // Si assegna 20

    printf("num: %d\n", num);

    // Visualizzazione elementi della matrice
    for (int i=0; i<ROWS; i++) {
        printf("ROW[%d] : ", i);
        for (int y=0; y<COLS; y++)
            printf("%d | ", matrix_b[i][y]);
        printf("\n");
    }

    return(EXIT_SUCCESS);
}

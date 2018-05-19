#include <stdio.h>
#include <stdlib.h>

#define ROWS    2
#define COLS    3

int main(void) {
    // Array bidimensionale e' sinonimo di matrice

    int i, j; /* rows and cols indexes */

    // Dichiarazione di una matrice di tipo intero
    // Inizializzazione a 0 di ciascun elemento
    int matrix_a[ROWS][COLS] = { {0} };

    // Inizializzazione contestualmente alla dichiarazione
    // Valgono comunque le regole per i vettori
    int matrix_b[ROWS][COLS] = { {10, 20, 30},
                                 {40, 50, 60} };

    /* It would have been the same:
    int matrix_b[][COLS] = { {10,20,30},
                             {40,50,60 }; */

    /* Calcolo dell'occupazione di memoria */
    int n_bytes = sizeof(matrix_a);

    /* Calcolo del numero degli elementi */
    int n_elem = n_bytes / sizeof(int);

    /* Calcolo del numero di colonne */
    int n_cols = sizeof(matrix_a[0]) / sizeof(int);

    /* Calcolo del numero di righe */
    int n_rows = n_elem / n_cols;

    printf("Matrix elements: %d\n", n_elem);
    printf("Matrix bytes: %d\n", n_bytes);
    printf("Matrix cols: %d\n", n_cols);
    printf("Matrix rows: %d\n", n_rows);

    /* Pay attention when using sizeof(), because it works only on objects
    statically allocated */

    /* How to assign new values to the matrix */
    matrix_a[1][2] = 39;
    matrix_a[2][0] = 99;
    matrix_a[0][0] = 10;
    matrix_a[0][1] = 86;

    printf("Print each element of matrix_a, scanning by rows:\n");
    for (i=0; i<ROWS; i++) {
        printf("row %d: ", i);
        for (j=0; j<COLS; j++)
            printf("%2d | ", matrix_a[i][j]);
        printf("\n");
    }

    printf("Print each element of matrix_b, scanning by cols:\n");
    for (i=0; i<COLS; i++) {
        printf("col %d: ", i);
        for (j=0; j<ROWS; j++)
            printf("%2d | ", matrix_b[j][i]);
        printf("\n");
    }

    return(EXIT_SUCCESS);
}

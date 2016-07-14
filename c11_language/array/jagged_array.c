#include <stdio.h>
#include <stdlib.h>

/* Uno 'Jagged array', letteralmente array seghettato, e' una struttura dati
di tipo array multidimensionale le cui colonne hanno dimensioni differenti. */

int main(void) {
    // Dichiarazione di un array di puntatori a interi
    int (*(array[])) = {
        // Ciascuna riga si inizializza mediante i 'compund literals'
        (int[]) { 10, 20},
        (int[]) { 30, 40, 50},
        (int[]) { 60, 70, 80, 90},
        (int[]) { 100 }
    };

    printf("%d\n", *(*(array + 0)));
    printf("%d\n", *(*(array + 0) + 1));
    printf("%d\n", *(*(array + 1)));
    printf("%d\n", *(*(array + 1) + 1));
    printf("%d\n", *(*(array + 1) + 2));
    printf("%d\n", *(*(array + 2)));
    printf("%d\n", *(*(array + 2) + 1));
    printf("%d\n", *(*(array + 2) + 2));
    printf("%d\n", *(*(array + 2) + 3));
    printf("%d\n", *(*(array + 3)));

    // Print the first element of each row
    for (int i=0; i<4; i++)
        printf("%d\n", *(*(array + i)));

    return(EXIT_SUCCESS);
}

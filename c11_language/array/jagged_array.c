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
    return(EXIT_SUCCESS);
}

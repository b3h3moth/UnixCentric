#include <stdio.h>
#include <stdlib.h>

#define ROWS    2
#define COLS    3

int main(void) {
    
    int data[ROWS][COLS] = {
        {10, 20, 30},   // Row 1
        {40, 50, 60},   // Row 2
    };

    // Dichiarazione di un puntatore a un array di interi
    int (*p)[3] = data;

    /* Premessa: L'operatore di subscript '[]' ha una precedenza maggiore 
    rispetto all'indirezione '*p', tuttavia inserendo l'indirezione tra
    parentesi la precedenza della stessa sara' maggiore. */

    // 'p' punta alla prima riga della matrice
    p = data;
    
    // Stampa del primo elemento della prima riga della matrice
    printf("%d\n", (*p)[0]);
    printf("%d\n", (*(*p + 0) + 0) );


    return(EXIT_SUCCESS);
}

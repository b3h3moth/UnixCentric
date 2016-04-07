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
    parentesi la precedenza della stessa sara' maggiore. Se non fosse stata
    inserita l'indirezione tra parentesi l'istruzione risultante sarebbe stata
    int *p[3], ovvero un array di puntatori, ben diverso da un puntatore a un 
    array di interi. */

    // 'p' punta alla prima riga della matrice
    p = data;

    // Assegna nuovo valore al primo elemento della prima riga della matrice
    printf("old: %d\n", *((*p) + 0));
    (*p)[0] = 123;
    printf("new: %d\n", *((*p) + 0));

    // Assegna nuovo valore al secondo elemento della prima riga della matrice
    printf("old: %d\n", *((*p) + 1));
    (*p)[1] = 768;
    printf("new: %d\n", *((*p) + 1));

    // Assegna nuovo valore al primo elemento della seconda riga della matrice
    printf("old: %d\n", *((*p) + 3));
    p[1][0] = 999;
    printf("new: %d\n", *((*p) + 3));

    // Assegna nuovo valore al terzo elemento della seconda riga della matrice
    printf("old: %d\n", *((*p) + 5));
    p[1][2] = 2016;
    printf("new: %d\n", *((*p) + 5));

    for (int i=0; i<6; i++) {
        if ((i % 3) == 0)
            puts(" ");
        printf("%4d, ", (*p)[i]);
    }

    return(EXIT_SUCCESS);
}

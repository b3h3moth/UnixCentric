#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' di utilizzare il nome di un array 
multidimensionale come un puntatore a un array di interi, dopodiche' verificare
che si possa lavorare con tale puntatore sia come un Lvalue sia come un Rvalue.
*/

int main(void) {
    int matrix[3][4] = { {1,2,3,4},{11,12,13,14},{21,22,23,24} };

    /* Il nome dell'array 'matrix' e' un puntatore costante a un array di 
    interi, l'indirizzo di partenza pertanto puo' essere ottenuto mediante 
    differenti espressioni. */
    printf("%p\n", (void *)*(matrix + 0));
    printf("%p\n", (void *)matrix);
    printf("%p\n", (void *)&matrix[0][0]);

    // Si utilizza come un Lvalue, modificando alcuni elementi
    *(*(matrix + 0) + 1) = 98;
    *(*(matrix + 1) + 2) = 99;
    *(*(matrix + 2) + 3) = 100;

    for (int i=0; i<3; i++)
        for (int j=0; j<4; j++)
            printf("%d, ", *(*(matrix + i) + j));

    return(EXIT_SUCCESS);
}

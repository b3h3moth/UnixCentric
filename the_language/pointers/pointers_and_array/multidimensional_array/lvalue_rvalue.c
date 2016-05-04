#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' di verificare che il nome di un array 
multidimensionale altro non e' che un puntatore a un array di interi, stampando
l'indirizzo iniziale dell'array stesso. Infine si utilizza tale puntatore 
sia come se fosse un Lvalue sia come se fosse un Rvalue.
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

    // Si utilizza come Rvalue, stampando a video ciascun elemento
    for (int i=0; i<3; i++)
        for (int j=0; j<4; j++)
            printf("%d, ", *(*(matrix + i) + j));

    /* I subscripts sono una sorta di forma alternativa di indirezione, quindi
    e' possibile utilizzarmi assieme */
    printf("\nsubscripts/indirection together\nelem: %d\n", *(matrix[2] + 1));
    
    return(EXIT_SUCCESS);
}

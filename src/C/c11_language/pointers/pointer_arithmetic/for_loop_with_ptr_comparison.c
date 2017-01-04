#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' di verificare l'aritmetica dei puntatori, nel caso
di una comparazione tra gli stessi, nello specifico in un ciclo for */

int main(void) {
    int vec[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900 };
    int *ptr;

    /* Le similitudini tra puntatori ed array vengono fuori in
    tutta la loro essenza allorquando, nel ciclo for, sono messi
    a confronto gli indirizzi di memoria del puntatore 'ptr' e del
    vettore 'vec'. */

    for (ptr = vec; ptr <= vec+8; ptr++)
        printf("%d, ", *ptr);

    return(EXIT_SUCCESS);
}

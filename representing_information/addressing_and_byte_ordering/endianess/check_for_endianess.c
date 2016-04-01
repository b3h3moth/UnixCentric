#include <stdio.h>
#include <stdlib.h>

// Creazione di un array di memoria statica
char vec[4] = {'a', 'b', 'c', 'd'};

// Function Prototypes
char *bits(char ch);


int main(void) {
    // Puntatori all'inizio di 'vec'
    char    *ptochr = vec;
    short   *ptoshr = (short *)vec;
    int     *ptoint = (int *)vec;
    float   *ptoflt = (float *)vec;

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

// Creazione di un array di memoria statica
char vec[4] = {'a', 'b', 'c', 'd'};

// Function Prototypes
char *bits(char ch);
int big_endian(void);


int main(void) {
    // Puntatori all'inizio di 'vec'
    char    *ptochr = vec;
    short   *ptoshr = (short *)vec;
    int     *ptoint = (int *)vec;
    float   *ptoflt = (float *)vec;

    return(EXIT_SUCCESS);
}


int big_endian(void) {
    long val = 1;

    return !(*((char *)(&x)));
}

#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' di spezzare un array multidimensionale nelle sue
componenti individuali, in modo tale da rendere evidente la relazione che
intercorre con i puntatori. */

int main(void) {
    int data[2][3][5];
    int *p;
    int i=1;

    // Inizializza ciascun elemento dell'array utilizzando la variabile 'i'
    for (p = &data[0][0][0]; p <= &data[2-1][3-1][5-1]; p++, i++)
        *p = i;

    puts("\nArray initialized.\n");

    int (*pa)[3][5] = data;
    int (*pb)[5] = data[1];
    int  *pc = data[2][3];

    printf("%p\n", (void*)pa);
    printf("%p\n", (void*)pb);
    printf("%p\n", (void*)pc);

    return(EXIT_SUCCESS);
}

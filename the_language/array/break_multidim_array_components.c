#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' di spezzare un array multidimensionale nelle sue
componenti individuali, in modo tale da rendere evidente la relazione che
intercorre con i puntatori. */

int main(void) {
    int data[2][3][5];

    int (*pa)[3][5] = data;
    int (*pb)[5] = data[0];
    int  *pc = data[2][3];

    printf("%#x\n", (unsigned int)pa);
    printf("%#x\n", (unsigned int)pb);
    printf("%#x\n", (unsigned int)pc-180);

    return(EXIT_SUCCESS);
}

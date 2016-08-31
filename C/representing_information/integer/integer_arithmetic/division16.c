#include <stdio.h>
#include <stdlib.h>

#define DIV 16

int div16(int num);

int main(void) {
    // Ciascun numero relativo intero sara' diviso per DIV
    const int numbers[] = {165,-165,48,-48,32,-32,197,-197,1,-1,0,234,-234};
    const int elem_of_numbers = sizeof(numbers) / sizeof(numbers[0]);

    for(int i=0; i<elem_of_numbers; i++)
        printf("%5d / %2d = %3d\n", numbers[i], DIV, div16(numbers[i]));

    return(EXIT_SUCCESS);
}

// Ritorna il risultato della divisione num / DIV
int div16(int num) {
    /* bias puo' essere:
    '0'  se (num >= 0);
    '15' se  (num < 0);
    */
    int bias = (num >> 31) & 0xF;
    return (num + bias) >> 4;
}

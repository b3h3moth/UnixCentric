#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Modificare un campo di bit
    Si vogliono modificare i bit della variabile 'num' dal bit 4 al bit 6 */
    unsigned int num = 0;
    num = num & ~0x0070 | 0x0050; /* L'operatore bitwise AND '&' ha una
                                     precedenza maggiore rispetto all'operatore
                                     bitwise OR '|', quindi le parentesi in
                                     questo caso non sono necessarie, tuttavia
                                     inserirle per migliorare la leggibilita'
                                     non sarebbe affatto un reato */
    printf("(dec.) %d - (hex) 0x%x\n", num, num);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

unsigned char is_zero(unsigned char val);
unsigned char is_equal(unsigned char x, unsigned char y);
unsigned char is_greater(unsigned char x, unsigned char y);
unsigned char is_less(unsigned char x, unsigned char y);

/* Lo scopo del programma e' di eseguire la comparazione tra due valori - nel
caso specifico 'unsigned char' - senza adoperare operatori di confronto, ma 
soltanto le operazioni sui bit. 

Nota: Ciascuna funzione ritorna 1 in caso di esito positivo, 0 altrimenti.*/

int main(void) {
    unsigned char val1 = 255;
    unsigned char val2 = 250;

    if (is_greater(val1, val2) == 1)
        printf("%d > %d\n", val1, val2);
    else
        printf("%d > %d\n", val1, val2);

    /* Testing all functions is simple */

    return(EXIT_SUCCESS);
}

/* Verifica se il parametro passato come argomento vale zero */
unsigned char is_zero(unsigned char val) {

    return ~((val & (1<<7)) >> 7 |
             (val & (1<<6)) >> 6 |
             (val & (1<<5)) >> 5 |
             (val & (1<<4)) >> 4 |
             (val & (1<<3)) >> 3 |
             (val & (1<<2)) >> 2 |
             (val & (1<<1)) >> 1 | 
             (val & 1)) & 1;
}
M

/* Verifica se i due parametri hanno il medesimo valore */
unsigned char is_equal(unsigned char x, unsigned char y) {
    return(is_zero(x ^ y));
}

/* Verifica se il parametro 'x' e' maggiore rispetto ad 'y' */
unsigned char is_greater(unsigned char x, unsigned char y) {
    unsigned char uc1, uc2;

    uc1 = ~x & y;
    uc2 = x & ~y;

    uc1 = uc1 | (uc1 >> 1);
    uc1 = uc1 | (uc1 >> 2);
    uc1 = uc1 | (uc1 >> 4);

    return ~is_zero(~uc1 & uc2) & 1;
}

/* Verifica se il parametro 'x' e' minore rispetto ad 'y' */
unsigned char is_less(unsigned char x, unsigned char y) {
    return (!is_equal(x,y) && !is_greater(x,y));
}

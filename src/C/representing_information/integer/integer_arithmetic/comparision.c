#include <stdio.h>
#include <stdlib.h>

unsigned char is_zero(unsigned char val);
unsigned char is_equal(unsigned char x, unsigned char y);

/* Si esegue la comparazione tra due 'unsigned char' senza adoperare
operatori di confronto, ma solo con tecniche di shifting, AND e XOR 
logico. */

int main(void) {
    unsigned char val1 = 252;
    unsigned char val2 = 254;

    if (is_equal(val1, val2))
        printf("Sono diversi\n");
    else
        printf("Sono uguali\n");

    return(EXIT_SUCCESS);
}

/* Verifica se il parametro passato come argomentoo e' zero o meno */
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

/* Verifica se i due parametri sono uguali o meno */
unsigned char is_equal(unsigned char x, unsigned char y) {
    return(is_zero(x ^ y));
}

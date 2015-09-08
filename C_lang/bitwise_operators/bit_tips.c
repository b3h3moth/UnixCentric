#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Si imposta ciascun bit di un 'unsigned short' - 2 byte, 16 bit - a 1
    mediante l'operatore di complemento. Nel caso specifico trattasi del valore
    massimo permesso da quel tipo di dato, ovvero 65535. */
    unsigned short us_num1 = ~0; // da 0000000000000000 a 1111111111111111

    /* Se si tentasse di assegnare ad una variabile di tipo 'unsigned short'
    un valore maggiore di appena una sola unita' rispetto al massimo
    consentito, cosa succedderebbe?
    Zero, uno o cento non fa differenza, sara' superato il limite massimo
    (overflow) consentito da quel tipo di dato, per cui sia il compilatore GCC
    sia il compilatore Clang (LLVM) troncheranno il valore della variabile
    impostandolo 0, il tutto condito da un messaggio di warning sullo stdout.*/
    unsigned short us_num2 = 65536;
    unsigned short us_num3 = us_num1 + 1;

    printf("%d %d %d\n", us_num1, us_num2, us_num3);
    
    return(EXIT_SUCCESS);
}

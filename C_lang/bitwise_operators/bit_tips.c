#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Si imposta ciascun bit a 1 con l'operatore di complemento, si sta
    operando su un unsigned short di due byte, ovvero 16 bit. Nel caso
    specifico quindi si sta impostando il valore massimo permesso da quel tipo
    di dato, ovverp 65535. */
    unsigned short us_num1 = ~0;

    /* Sia il compilatore GCC sia Clang imposteranno a 0 il risultato, poiche'
    si e' inserito un numero maggiore rispetto al massimo consentito. */
    unsigned short us_num2 = 65536;
    unsigned short us_num3 = us_num1 + 1;

    printf("%d %d %d\n", us_num1, us_num2, us_num3);
    return(EXIT_SUCCESS);
}

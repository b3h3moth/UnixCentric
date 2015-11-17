#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Con una word di 32 bit e complemento a due, il tipo di dato 'int' ha un
    valore massimo positivo uguale a 2147483647, e se volessi il minimo valore
    negativo rappresentabile? */
    int max_int = 2147483647;
    int min_int = max_int + 1;
   
    /* I numeri rappresentabili su un calcolatore sono finiti, per cui
    sommando uno al valore massimo e' come se si chiudesse il cerchio dei 
    postivi per aprire nuovamente quello dei negativi, ma il concetto 
    fondamentale e'che il calcolatore lavora coi numeri binari, pertanto:

    0111 1111 1111 1111 1111 1111 1111 1111 +        2147483647 +
                                          1 =                 1 =
    1000 0000 0000 0000 0000 0000 0000 0000         -2147483648        */
    
    printf("max_int = %d\tmin_int = %d\n", max_int, min_int);

    return(EXIT_SUCCESS);
}

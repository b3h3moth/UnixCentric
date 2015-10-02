#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Con una word di 32 bit e complemento a due, il tipo di dato int ha un
    valore massimo positivo uguale a 2147483647, se volessi il minimo valore
    negativo rappresentabile? */
    int max_int = 2147483647;
    int min_int = max_int + 1;
   
    /* I numeri rappresentabili su un calcolatore sono finiti, per cui
    sommando uno al valore massimo e' come se si tornasse al punto di partenza
    */
    printf("max_int = %d\tmin_int = %d\n", max_int, min_int);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    /* Con una word di 32 bit e complemento a due, il tipo di dato 'int' ha un
    valore massimo positivo uguale a 2147483647, e se volessi il minimo valore
    negativo rappresentabile nel modo piu' semplice possibile? */
    int max_int = 2147483647;
    int min_int = max_int + 1;
   
    /* I numeri rappresentabili su un calcolatore sono finiti, per cui
    sommando uno al valore massimo e' come se si chiudesse il cerchio dei 
    postivi per aprire nuovamente quello dei negativi. Ovvero:

    0111 1111 1111 1111 1111 1111 1111 1111 +        2147483647 +
                                          1 =                 1 =
    1000 0000 0000 0000 0000 0000 0000 0000         -2147483648        
    
    Il range degli interi 'int' o 'signed int' va difatti 
    da -2147483647 a +2147483647. Numeri peraltro ottenibili ancor piu'
    velocemente mediante le macro predefinite INT_MIN, INT_MAX collocate nel
    file header <limits.h> */
    
    printf("max_int = %d\tmin_int = %d\n", max_int, min_int);
    printf("INT_MAX = %d\tINT_MIN = %d\n", INT_MAX, INT_MIN);

    return(EXIT_SUCCESS);
}

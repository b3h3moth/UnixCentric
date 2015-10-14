#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Lo scopo del programma e' di verificare la correttezza della somma algebrica
tra due valori in complemento a due, e quindi di segnalare un eventuale
overflow, sia positivo sia negativo */

int check_overflow(int x, int y);

int main(void) {
    int val1 = 2147483647;
    int val2 = 1;
    int val3 = 2;

    printf("MAX_INT: %11d\n", INT_MAX);
    printf("MIN_INT: %11d\n", INT_MIN);

    if (check_overflow(val1, val2))
        printf("%d + %d = %d\n", val1, val2, 1);

    return(EXIT_SUCCESS);
}

int check_overflow(int x, int y) {
    int sum = x + y;

    int negative_overflow = x < 0 && y < 0 && sum >= 0;
    int positive_overflow = x >= 0 && y >= 0 && sum < 0;

    return !negative_overflow && !positive_overflow;
    /*
    if (INT_MAX <= x + y)
        return 0;
    else if ( x + y < INT_MIN)
        return 0;
    else 
        return 1;
    */
}

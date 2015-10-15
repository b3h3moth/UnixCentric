#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Lo scopo del programma e' di verificare la correttezza della somma algebrica
tra due valori in complemento a due, e quindi di segnalare un eventuale
overflow, sia positivo sia negativo */

int check_overflow(int x, int y);
int sum(int x, int y);

int main(void) {
    int val1 = 2147483646;
    int val2 = 1;
    int val3 = 2;

    printf("MAX_INT: %11d\n", INT_MAX);
    printf("MIN_INT: %11d\n", INT_MIN);

    int res1 = check_overflow(val1, val2);
    printf("%d + %d = %d (res: %d\n", val1, val2, val1+val2, res1);

    int res2 = check_overflow(val1, val3);
    printf("%d + %d = %d (res: %d - overflow)\n", val1, val3, val1+val3, res2);

    return(EXIT_SUCCESS);
}

int check_overflow(int x, int y) {
    int sum = x + y;

    return (INT_MAX <= sum || sum < INT_MIN);

/* Just another method
    int negative_overflow = x < 0 && y < 0 && sum >= 0;
    int positive_overflow = x >= 0 && y >= 0 && sum < 0;

    return !negative_overflow && !positive_overflow;
*/
}

int sum(int x, int y) {
}

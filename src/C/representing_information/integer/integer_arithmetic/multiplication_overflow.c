#include <stdio.h>
#include <stdlib.h>

int check_overflow(int x, int y);

int main(void) {
    int val1 = 900000000;
    int val2 = 2;
    int val3 = val2 + 1;

    int res1 = check_overflow(val1, val2);
    int res2 = check_overflow(val1, val3);

    if (res1)
        printf("%d * %d = %d\n", val1, val2, val1*val2);
    else
        printf("%d * %d = %d (Err: Integer Overflow)\n", val1, val2, val1*val2);

    if (res2)
        printf("%d * %d = %d\n", val1, val3, val1*val3);
    else
        printf("%d * %d = %d (Err: Integer Overflow)\n", val1, val3, val1*val3);

    return(EXIT_SUCCESS);
}

/* Verifica l'overflow */
int check_overflow(int x, int y) {
    int tot = x * y;

    return !x || tot/x == y;
}

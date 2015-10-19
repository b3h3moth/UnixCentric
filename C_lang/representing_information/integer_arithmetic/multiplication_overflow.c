#include <stdio.h>
#include <stdlib.h>

int check_overflow(int x, int y);

int main(void) {
    int val1 = 900000000;
    int val2 = 2;
    int val3 = 3;

    int result1 = check_overflow(val1, val2);
    int result2 = check_overflow(val1, val3);

    if (result1)
        printf("%d * %d = %d\n", val1, val2, val1*val2);
    else
        printf("Err. %d - overflow\n", result1);

    if (result2)
        printf("%d * %d = %d\n", val1, val3, val1*val3);
    else
        printf("Err. %d - overflow\n", result2);

    return(EXIT_SUCCESS);
}

int check_overflow(int x, int y) {
    int res = x * y;

    return !x || res/x == y;
}

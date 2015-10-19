#include <stdio.h>
#include <stdlib.h>

int check_overflow(int x, int y);

int main(void) {
    int val1 = 900000000;
    int val2 = 2;

    int result = check_overflow(val1, val2);

    if (result)
        printf("%d * %d = %d\n", val1, val2, val1*val2);
    else
        printf("Err. %d - overflow\n", result);

    return(EXIT_SUCCESS);
}

int check_overflow(int x, int y) {
    int res = x * y;

    return !x || res/x == y;
}

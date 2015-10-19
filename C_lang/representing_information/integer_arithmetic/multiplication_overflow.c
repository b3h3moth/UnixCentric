#include <stdio.h>
#include <stdlib.h>

int check_overflow(int x, int y);

int main(void) {
    return(EXIT_SUCCESS);
}

int check_overflow(int x, int y) {
    int result = x * y;

    return !x || result/x == y;
}

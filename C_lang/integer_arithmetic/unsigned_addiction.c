#include <stdio.h>
#include <stdlib.h>

int check_overflow(unsigned x, unsigned y);

int main(void) {
    unsigned val1 = 5;
    unsigned val2 = 6;

    int res = check_overflow(val1, val2);
    printf("res: %d\n", res);

    return(EXIT_SUCCESS);
}

// Returna 1 se gli argomenti possono essere sommati senza overlow
int check_overflow(unsigned x, unsigned y) {
    unsigned sum = x + y;

    return (sum >= x);
}

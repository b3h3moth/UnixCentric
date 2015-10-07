#include <stdio.h>
#include <stdlib.h>

int check_overflow(unsigned x, unsigned y);

int main(void) {
    unsigned val1 = 4294967294; // unsigned int max number is 42949672945U
    unsigned val2 = 1;
    unsigned val3 = 2;

    int res1 = check_overflow(val1, val2);
    printf("res: %d\n", res1);
    int res2 = check_overflow(val1, val3);
    printf("res: %d\n", res2);

    return(EXIT_SUCCESS);
}

// Returna 1 se gli argomenti possono essere sommati senza overlow
int check_overflow(unsigned x, unsigned y) {
    unsigned sum = x + y;

    return (sum >= x);
}

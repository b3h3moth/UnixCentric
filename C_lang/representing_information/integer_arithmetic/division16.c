#include <stdio.h>
#include <stdlib.h>

int div16(int num);

int main(void) {
    const int val = 165;

    printf("%d / %d = %d\n", val, 16, div16(val));

    return(EXIT_SUCCESS);
}

// Ritorna il risultato della divisione num / 16
int div16(int num) {
    int bias = (num >> 31) & 0xF;
    return (num + bias) >> 4;
}

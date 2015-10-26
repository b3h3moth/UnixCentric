#include <stdio.h>
#include <stdlib.h>

int div16(int num);

int main(void) {
    return(EXIT_SUCCESS);
}

int div16(int num) {
    int bias = (x >> 31) & 0xF;
    return (x + bias) >> 4;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int big_endian(void);

int main(void) {
    if (!big_endian())
        fputs("Big Endian", stdout);
    else
        fputs("Little Endian", stdout);

    return(EXIT_SUCCESS);
}

// It returns true if the byte ordering is Big-endian
int big_endian(void) {
    int32_t val = 1;
    return !(*((char *)(&val)));
}


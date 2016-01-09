#include <stdio.h>
#include <stdlib.h>

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
    long val = 1;
    return !(*((char *)(&val)));
}


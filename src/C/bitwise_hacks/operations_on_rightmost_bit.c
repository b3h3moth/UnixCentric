#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned char n = 200; /* 11001000 (0xc8) */

    /* turn off the rightmost bit in a word */
    unsigned char res = n & (n - 1);
    /*
    11001000 & (11001000 - 00000001)
    11001000 & 11000111
    11000000
    */
    printf("before: %d (0x%x)\nafter : %d (0x%x)\n", n, n, res, res);

    return(EXIT_SUCCESS);
}

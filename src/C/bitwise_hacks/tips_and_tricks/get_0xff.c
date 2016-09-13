#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int val = (1 << 8) - 1;    // 0xFF (hex), 255 (dec)

    printf("%#x (hex), %d (dec)\n", val, val);

    return(EXIT_SUCCESS);
}

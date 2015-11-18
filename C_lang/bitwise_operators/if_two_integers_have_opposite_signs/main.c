#include <stdio.h>
#include <stdlib.h>

/* The program's purpose is to verify if two integers have opposite signs.
true  (1) = opposite signs
false (0) = opposite signs */

int main(void) {
    int x = 10;
    int y = 4;
    int z = -5;

    _Bool val1 = ((x ^ y) < 0);
    _Bool val2 = ((x ^ z) < 0);

    printf("%2d and %2d have opposite signs: %d (false)\n", x, y, val1);
    printf("%2d and %2d have opposite signs: %d (true)\n", x, z, val2);
    
    return(EXIT_SUCCESS);
}

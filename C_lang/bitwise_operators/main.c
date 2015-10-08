#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // to get CHAR_BIT, or 8

int main(void) {
    int val = 1;

    int size = sizeof(val);
    int bit_val = size * CHAR_BIT;
    int mask = 1 << (bit_val -1);

    printf("%d byte - %d bit\n", size, bit_val);

    for (int i=1; i<=bit_val; ++i) {

        if (val & 1)
            printf("1");
        else
            printf("0");

        val >>= 1;

        // Print 8 bit then add a space
        if ((i % 8 == 0) && (i != 0))
            printf(" ");
    }

    return(EXIT_SUCCESS);
}

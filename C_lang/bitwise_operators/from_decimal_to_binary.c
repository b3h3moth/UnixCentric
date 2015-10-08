#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // to get CHAR_BIT, or 8

int main(void) {
    int val = 1;

    int size = sizeof(val);
    int bit_val = size * CHAR_BIT;

    printf("%d byte - %d bit\n", size, bit_val);

    for (int i=0; i<bit_val; i++) {
        if (i == 8 || i==16 || i==24)
            printf(" ");
        if (val & (1 << i))
            printf("1");
        else
            printf("0");

    }

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // to get CHAR_BIT, or 8

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <decimal_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int val = strtol(argv[1], NULL, 10);

    int size = sizeof(val);
    int bit_val = size * CHAR_BIT;
    int mask = 1 << (bit_val - 1); // Work on Most Significant Bit

    printf("%d byte - %d bit\n", size, bit_val);

    for (int i=1; i<=bit_val; ++i) {

        // Print 0 if MSB (Most Significant Bit) is 0, 1 otherwise
        (val & mask) == 0 ? printf("0") : printf("1");

        val <<= 1;

        // Print 8 bit then add a space
        if ((i % 8 == 0) && (i != 0))
            printf(" ");
    }

    return(EXIT_SUCCESS);
}

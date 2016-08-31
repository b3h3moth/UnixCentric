#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void absolute_value(int val);

// The program's purpose is to extract the absolute value of an integer

int main(void) {
    int values[] = {0x0, -1, 0x00000001, 0xFFFFFF00, 0xFFFFFEFF, 10};

    for (int i=0; i<sizeof(values)/sizeof(values[0]); i++)
        absolute_value(values[i]);

    return(EXIT_SUCCESS);
}

/* The function absolute_value() extracts the LSB (Least Significant Bit) from
4 byte (32 bit) integer */
void absolute_value(int val) {
    /* It's equivalent to:
    mask = value >> 31 */
    int const mask = val >> (sizeof(int) * CHAR_BIT - 1);
    unsigned int result = (val + mask) ^ mask;

    printf("absolute (abs) value of %d is %u\n", val, result);
}

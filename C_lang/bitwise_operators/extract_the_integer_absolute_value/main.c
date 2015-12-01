#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// The program's purpose is to extract the absolute value of an integer

int main(void) {
    int value = -10;

    /* Extract the LSB (Least Significant Bit)
    on 4 byte (32 bit) int
    mask = value >> 31 */
    int const mask = value >> (sizeof(int) * CHAR_BIT - 1);

    unsigned int result = (value + mask) ^ mask;

    printf("absolute (abs) value of %d is %u\n", value, result);

    return(EXIT_SUCCESS);
}

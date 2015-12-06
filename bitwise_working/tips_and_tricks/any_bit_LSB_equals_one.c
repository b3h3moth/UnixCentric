#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int val = 0xA1B1C1FF; // 10101010 01010101 10101010 11111111
    int mask = 0xFF;      // 00000000 00000000 00000000 11111111
    
    // if any bit in the LSB (Least Significant Byte) of 'val' is 1, returns 1
    int result = !(~val & mask);
    
    printf("result: %d\n", result);

    return(EXIT_SUCCESS);
}

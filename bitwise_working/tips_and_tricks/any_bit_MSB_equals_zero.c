#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

int main(void) {
    int  val = 0x00FFFFFF; // 00000000 11111111 11111111 11111111
    int mask = 0xFF;       // 00000000 00000000 00000000 11111111
    
    // if any bit in the MSB (Most Significant Byte) of 'val' is 0, returns 1
    int result = !(val & (mask << CHAR_BIT * 3));

    // Logical operator '!' detects whether there is any nonzero bit in a word
    int res = !(~val & mask);

    assert(result == 1);
    assert(res == 1);
    
    printf("result: %d\n", result);
    printf("result: %d\n", res);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
    int val = ~0;  // 11111111 11111111 11111111 11111111
    int mask = ~0; // 11111111 11111111 11111111 11111111
    
    // if any bit of 'val' is 1, returns 1
    int result = !(val ^ mask);

    assert(result == 1);
    
    printf("result: %d\n", result);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int val = 0;
    int mask = -1; // 11111111 11111111 11111111 11111111
    
    // if any bit of 'val' is 0, returns 0
    int result = !(val & mask);
    
    printf("result: %d\n", result);

    return(EXIT_SUCCESS);
}

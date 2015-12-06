#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int val = -1;
    int mask = -1; // 11111111 11111111 11111111 11111111
    
    // if any bit of 'val' is 1, returns is one
    int result = !(val ^ mask);
    
    printf("%d\n", result);

    return(EXIT_SUCCESS);
}

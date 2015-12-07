#include <stdio.h>
#include <stdlib.h>

// The program's purpose is to check if the integer 'value' is a power of two

int main(void) {
    unsigned int val = 1024;
    _Bool result;

    if ((result = (val & (val - 1))) == 0)
        printf("%d is a power of two. Result: %d\n", val, result);

    
    return(EXIT_SUCCESS);
}

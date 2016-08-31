#include <stdio.h>
#include <stdlib.h>

// The program's purpose is to check if an integer is a power of two

int main(void) {
    unsigned int values[] = {2, 26, 64, 78, 88, 100, 31, 34, 1024, 16};
    _Bool result;

    for (int i=0; i<sizeof(values)/sizeof(values[0]); i++)
        if ((result = (values[i] & (values[i] - 1))) == 0)
            printf("%d is a power of two.\n", values[i]);
        else
            printf("%d is not a power of two.\n", values[i]);

    
    return(EXIT_SUCCESS);
}

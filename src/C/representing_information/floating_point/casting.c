#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ival = 32769;

    // Explicit casting from int to float
    float fval = ival;

    printf("From int: \'%d\'\n"
           "     to float: \'%f\'\n"
           "     IEEE 754: \'%e\'\n", ival, fval, fval);
    return(EXIT_SUCCESS);
}

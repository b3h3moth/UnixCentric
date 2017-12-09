#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {

    // Explicit casting from int to float
    int ival1 = 32769;
    float fval1 = (float)ival1;

    printf("From int: \'%d\'\n"
           "     to float: \'%f\'\n"
           "     IEEE 754: \'%e\'\n", ival1, fval1, fval1);

    // Explicit casting from int to float
    float fval2 = 4147483650.0;
    int ival2 = (int)fval2;
    printf("From float: \'%f\'\n"
           "     IEEE 754: \'%e\'\n"
           "     to int: \'%d\' INT_MAX: %d\n", fval2, fval2, ival2, INT_MAX);

    return(EXIT_SUCCESS);
}

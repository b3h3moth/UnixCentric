#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {

    int ival1 = 32769;
    float fval2 = 4147483650.0;
    float fval2a = -4147483650.0;

    /* Explicit casting from int to float */
    float fval1 = (float)ival1;

    /* Explicit casting from float to int */
    int ival2 = (int)fval2;
    int ival2a = (int)fval2a;

    /* Explicit casting from int to double */
    double dval1 = (double)ival1;

    /* Explicit casting from int to double */
    double dval2 = 5678765.6786789;
    int ival2b = (int)dval2;

    printf("From int: \'%d\'\n"
           "     to float: \'%f\'\n"
           "     IEEE 754, exponential notation: \'%e\'\n", 
           ival1, fval1, fval1);

    printf("From float: \'%f\'\n"
           "     IEEE 754, exponential notation: \'%e\'\n"
           "     to int: \'%d\' INT_MAX: %d\n", 
           fval2, fval2, ival2, INT_MAX);

    printf("From float: \'%f\'\n"
           "     IEEE 754, exponential notation: \'%e\'\n"
           "     to int: \'%d\' INT_MIN: %d\n", 
           fval2a, fval2a, ival2a, INT_MIN);

    printf("From int: \'%d\'\n"
           "     to double: \'%f\'\n"
           "     IEEE 754, exponential notation: \'%e\'\n", 
           ival1, dval1, dval1);

    printf("From double: \'%f\'\n"
           "     to int: \'%d\'\n"
           "     IEEE 754, exponential notation: \'%e\'\n", 
           dval2, ival2b, dval2);

    return(EXIT_SUCCESS);
}

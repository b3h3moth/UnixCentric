#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(void) {
    printf("Min single precision \'float\': %f\n"
           "    IEEE 754 \'scientific notation\': %e)\n", FLT_MIN, FLT_MIN);
    printf("Max single precision \'float\': %f\n"
            "(IEEE 754 \'scientific notation\': %e)\n", FLT_MAX, FLT_MAX);
    return(EXIT_SUCCESS);
}

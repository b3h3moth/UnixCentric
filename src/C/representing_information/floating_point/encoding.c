#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(void) {

    printf("Property   \tfloat \t\tdouble\t\t\tlong double\n");
    printf("mantissa:  \t%d    \t\t%d    \t\t\t%d\n", FLT_MANT_DIG, DBL_MANT_DIG, LDBL_MANT_DIG);
    printf("dec.digits:\t%d    \t\t%d    \t\t\t%d\n", FLT_DIG, DBL_DIG, LDBL_DIG);
    printf("max value: \t%9.5e \t%18.14e \t%22.17Le\n", FLT_MAX, DBL_MAX, LDBL_MAX);
    printf("min value: \t%9.5e \t%18.14e \t%22.17Le\n", FLT_MIN, DBL_MIN, LDBL_MIN);

    /* Write again with strings */
    return(EXIT_SUCCESS);
}

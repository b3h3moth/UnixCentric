#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(void) {

    printf("Single precision, data type \'float\'\n"
           "\tmin value: %f\n"
           "\texponential notation: %e\n"
           "\tmax value: %f\n"
           "\texponential notation: %e\n", 
           FLT_MIN, FLT_MIN, FLT_MAX, FLT_MAX);

    printf("Double precision, data type \'double\'\n"
           "\tmin value: %f\n"
           "\texponential notation: %e\n"
           "\tmax value: %f\n"
           "\texponential notation: %e\n", 
           DBL_MIN, DBL_MIN, DBL_MAX, DBL_MAX);

    return(EXIT_SUCCESS);
}

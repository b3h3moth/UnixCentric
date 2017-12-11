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

    return(EXIT_SUCCESS);
}

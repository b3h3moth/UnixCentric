#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ival = 32769;
    float fval = (float)ival;

    printf("from int %d to float %lf (IEEE 754: %e)\n", ival, fval, fval);
    return(EXIT_SUCCESS);
}

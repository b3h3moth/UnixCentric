#include <stdio.h>
#include <stdlib.h>

/* Sia per interi 'unsigned' sia per interi in "two's complement" la 
moltiplicazione potrebbe essere sostituita da shifting e addizione, 
o sottrazione */

int main(void) {

    // The total is 15 (5*3)
    int vala = 5;
    int resx = (vala << 1) + vala;
    printf("%d\n", resx);

    // The total is 9 (3*3)
    int valb = 3;
    int resy = (valb << 1) + valb;
    printf("%d\n", resy);

    // The total is 6 (1*6)
    int valc = 1;
    int resw = (valc << 2) + (valc << 1);
    printf("%d\n", resw);

    // The total is 31 (1*31)
    int resz = (valc << 5) - valc;
    printf("%d\n", resz);

    return(EXIT_SUCCESS);
}

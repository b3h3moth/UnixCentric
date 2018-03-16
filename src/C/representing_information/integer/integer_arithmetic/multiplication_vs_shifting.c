#include <stdio.h>
#include <stdlib.h>

/* Sia per interi 'unsigned' sia per interi in "two's complement" la 
moltiplicazione potrebbe essere sostituita da shifting e addizione, 
o sottrazione, il programma peraltro cosi facendo potrebbe essere piu'
performante */

int main(void) {
    int val = 1;

    // The total is 14
    int resx = (val << 3) + (val << 2) + (val << 1);
    // The total is 3
    int resy = (val << 1) + val;
    // The total is 6
    int resw = (val << 2) + (val << 1);
    // The total is 31
    int resz = (val << 5) - val;
    // The total is -6
    int resk = (val << 1) - (val << 3);
    // The total is 55
    int resj = (val << 6) - (val << 3) - val;

    printf("%d\n", resx);
    printf("%d\n", resy);
    printf("%d\n", resw);
    printf("%d\n", resz);
    printf("%d\n", resk);
    printf("%d\n", resj);

    return(EXIT_SUCCESS);
}

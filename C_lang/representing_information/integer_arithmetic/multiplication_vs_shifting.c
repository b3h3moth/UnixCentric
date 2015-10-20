#include <stdio.h>
#include <stdlib.h>

/* Sia per interi 'unsigned' sia per interi in "two's complement" la 
moltiplicazione potrebbe essere sostituita da shifting e addizione, 
o sottrazione */

int main(void) {
    int val1 = 4;
    int val2 = 8;

    int res1 = val1 * val2;
    int res2 = (2 << 3) + (2 << 3); // 32
    int res3 = (2 << 4);            // 32

    printf("%d * %d = %d\n", val1, val2, res1);
    printf("%d + %d = %d - %d\n", (2 << 3), (2 << 3), res2, res3);

    // The total is 15 (5*3)
    int val3 = 5;
    int res4 = (val3 << 1) + val3;
    printf("%d\n", res4);

    // The total is 9 (3*3)
    int val4 = 3;
    int res5 = (val4 << 1) + val4;
    printf("%d\n", res5);

    // The total is 6 (1*6)
    int val5 = 1;
    int res6 = (x<<2) + (x<<1);
    printf("%d\n", res6);


    return(EXIT_SUCCESS);
}

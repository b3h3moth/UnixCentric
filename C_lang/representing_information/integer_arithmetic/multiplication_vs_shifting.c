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

    return(EXIT_SUCCESS);
}

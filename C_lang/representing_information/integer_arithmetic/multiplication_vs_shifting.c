#include <stdio.h>
#include <stdlib.h>

/* Sia per interi 'unsigned' sia per interi in "two's complement" la 
moltiplicazione potrebbe essere sostituita da shifting e addizione, ma solo
se si tratta di potenze del 2 */

int main(void) {
    int val1 = 4;
    int val2 = 8;

    int res1 = val1 * val2;
    int res2 = (2 << 3) + (2 << 3);

    printf("%d * %d = %d\n", val1, val2, res1);
    printf("%d + %d = %d\n", (2 << 3), (2 << 3), res2);

    return(EXIT_SUCCESS);
}

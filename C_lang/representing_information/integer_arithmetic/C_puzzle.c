#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int val1 = INT_MIN;

    if ( (val1 > 0) || (val1 -1 < 0) )
        printf("true\n");
    else
        printf("false; %d - 1 = %d\n", INT_MIN, INT_MIN-1); // integer overflow

    if ( (val1 & 7) != 7 || (val1<<29 < 0) )
        printf("true\n");

    // 65535 = 0xFFFF, x*x = -131071, 0xFFFE0001
    int val2 = 65535;
    int res2 = val2*val2;

    if ((val2 * val2) >= 0)
        printf("true\n");
    else
        printf("false; %d(%#x) * %d(%#x) = %d(%#x)\n", val2, val2, val2, val2, \
                res2, res2);

    // Se val2 è un non-negativo allora -val2 e' un non-positivo
    if ( (val2 < 0) || (-val2 <= 0) )
        printf("true\n");

    return(EXIT_SUCCESS);
}

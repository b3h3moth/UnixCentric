#include <stdio.h>
#include <stdlib.h>

#define v(a,b,c)    a ## b ## c

int main(void) {
    int numbers[] = { v(1,2,3), v(4,5,6), v(7,8,), v(9,,), v(,,10), v(,,) };

    for (int i=0; i<sizeof(numbers)/sizeof(numbers[0]); i++)
        printf("%3d\n", numbers[i]);

    return(EXIT_SUCCESS);
}

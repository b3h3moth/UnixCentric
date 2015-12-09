#include <stdio.h>
#include <stdlib.h>

int get_rightmost_one_bit(int value);

int main(void) {

    return(EXIT_SUCCESS);
}

/* Thi get_rightmost_one_bit() function returns the rightmost 1 bit within
a integer 'int' value */
int get_rightmost_one_bit(int value) {
    return (value & -value);
}

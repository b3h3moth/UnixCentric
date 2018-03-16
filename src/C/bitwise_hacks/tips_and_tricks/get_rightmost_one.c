#include <stdio.h>
#include <stdlib.h>

int get_rightmost_one_bit(unsigned value);

int main(void) {
    int values[] = { 0xFF, 0xA, 0x14, 0x0100, 0xABC, 0x6600, 0x0200};
    int i;

    for (i=0; i<sizeof(values)/sizeof(*values); i++)
        printf("%#6x (hex) %6d (dec) righmost 1 is: %3d\n",\
                values[i], values[i], get_rightmost_one_bit(values[i]));

    return(EXIT_SUCCESS);
}

/* Thi get_rightmost_one_bit() function returns the rightmost 1 bit within
an integer 'int' value */
int get_rightmost_one_bit(unsigned value) {
    return (value & -value);
}

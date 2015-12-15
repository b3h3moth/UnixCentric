#include <stdio.h>
#include <stdlib.h>

int any_odd_is_one(unsigned val);

int main(void) {
    return(EXIT_SUCCESS);
}

/* The function any_odd_is_one() returns 1 when any odd bit of an integer 
variable equals 1, 0 otherwise */
int any_odd_is_one(unsigned val) {
    // 0xaaaaaaaa = 10101010101010101010101010101010
    return !!(val & 0xaaaaaaaa); //
}

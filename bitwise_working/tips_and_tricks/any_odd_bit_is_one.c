#include <stdio.h>
#include <stdlib.h>


int any_odd_is_one(unsigned val);

int main(void) {
    int num[] = { 0xA, 0xF, 0x5, 0x8, 0xFF, 0x9a };


    if ( any_odd_is_one(num) )
        printf("Any odd bit of %#x is one\n", num);

    return(EXIT_SUCCESS);
}

/* The function any_odd_is_one() returns 1 when any odd bit of an integer 
variable equals 1, 0 otherwise */
int any_odd_is_one(unsigned val) {
    // 0xaaaaaaaa = 10101010101010101010101010101010
    return (val & 0xaaaaaaaa); //
}

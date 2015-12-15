#include <stdio.h>
#include <stdlib.h>

#define SIZE    (sizeof(num) / sizeof(num[0]))

int any_odd_is_one(unsigned val);

int main(void) {
    int num[] = { 0xFF, 0xA, 0x14, 0x0100, 0xABC, 0x6600, 0x0200 };

    for (int i=0; i<SIZE; i++) {
        if ( any_odd_is_one(num[i]) )
            printf("Any odd bit of %#4x is one\n", num[i]);
    }

    return(EXIT_SUCCESS);
}

/* The function any_odd_is_one() returns 1 when any odd bit of an integer 
variable equals 1, 0 otherwise */
int any_odd_is_one(unsigned val) {
    // 0xaaaaaaaa = 10101010101010101010101010101010
    return (val & 0xaaaaaaaa) != 0; //
}

#include <stdio.h>
#include <stdlib.h>

/* Lo scopo della funzione e' di moltiplicare due operandi unsigned char da 
8 bit e di ritornare un unsigned short da 16 bit */

unsigned short multip(unsigned char x, unsigned char y) {
    unsigned char i;
    unsigned short res = 0;

    for (i=0; i<8; i++) {
        if (y & 1) {
            res += x << i;
        }
        y >>= 1;
    }

    return res;
}

int main(void) {
    printf("%d\n", multip(255,255));

    return(EXIT_SUCCESS);
}

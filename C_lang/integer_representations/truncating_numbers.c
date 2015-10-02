#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Talvolta e' necessario convertire un tipo di dato in un altro di
    minor grandezza, in questo caso vi e' la possibilita' che taluni bit 
    possano essere troncati */

    // Casting da 'int' a 'short'
    int val1 = 53191;           // int 4 byte (32 bit)
    short val2 = (short) val1;  // short 2 byte (16 bit)
    unsigned val3 = 65535;
    unsigned short val4 = (unsigned short) val3;

    printf("from %#10x %7d\n  to %#10x %7d\n", val1, val1, val2, val2);
    printf("from %#10x %7d\n  to %#10x %7d\n", val3, val3, val4, val4);
    
    return(EXIT_SUCCESS);
}

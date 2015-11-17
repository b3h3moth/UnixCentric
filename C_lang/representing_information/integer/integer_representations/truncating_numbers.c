#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Talvolta e' necessario convertire un tipo di dato in un altro di
    minor grandezza, in questo caso vi e' la possibilita' che taluni bit 
    possano essere troncati */

    // Casting da 'int' a 'short'
    int val1 = 53191;                               // 4 byte (32 bit)
    short val2 = (short) val1;                      // 2 byte (16 bit)

    // Casting da 'unsigned' ad 'unsigned short'
    unsigned val3 = 65535;                          // 4 byte (32 bit)
    unsigned short val4 = (unsigned short) val3;    // 2 byte (16 bit)
    
    // Casting da 'int' a 'short'
    int val5 = -212748364;
    short val6 = (short) val5;
    int val7 = 212748364;
    short val8 = (short) val7;

    printf("from %#12x %11d\n  to %#12x %11d\n", val1, val1, val2, val2);
    printf("from %#12x %11d\n  to %#12x %11d\n", val3, val3, val4, val4);
    printf("from %#12x %11d\n  to %#12x %11d\n", val5, val5, val6, val6);
    printf("from %#12x %11d\n  to %#12x %11d\n", val7, val7, val8, val8);
    
    return(EXIT_SUCCESS);
}

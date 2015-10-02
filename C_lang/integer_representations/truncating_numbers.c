#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Talvolta e' necessario convertire un tipo di dato in un altro di
    minor grandezza, in questo caso vi e' la possibilita' che taluni bit 
    possano essere troncati */

    // Casting da 'int' a 'short'
    int val1 = 53191;           // int 4 byte (32 bit)
    short val2 = (short) val1;  // short 2 byte (16 bit)

    printf("val1 %#10x %7d\nval2 %#10x %7d\n", val1, val1, val2, val2);
    
    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Talvolta e' necessario convertire un tipo di dato in un altro di
    minor grandezza, in questo caso vi e' la possibilita' che taluni bit 
    possano essere troncati */

    // Casting da 'int' 'short'
    int val1 = 12345;           // int 4 byte (32 bit)
    short val2 = (short) val1;  // short 2 byte (16 bit)

    return(EXIT_SUCCESS);
}

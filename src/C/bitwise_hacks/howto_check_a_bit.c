#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Controllare un bit
    Si controlla se il bit numero 6 della variabile 'num1' e' pari a 1 */
    unsigned short num1 = 0x5A;   // 0000000001011010
    unsigned short i = 0x40;      // 0000000001000000
    
    if (num1 & i) 
        printf("The 6th bit of num1 variable is '1'\n");

    return(EXIT_SUCCESS);
}

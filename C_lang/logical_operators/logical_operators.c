#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Gli operatori logici in C sono: '||' (OR), '&&' (AND) e '!' (NOT), essi
    restituiscono 1 (TRUE) o 0 (FALSE) e non devono essere confusi con gli
    operatori bitwise. */

    unsigned int num1 = 0x66;   // 1100110 - 65 (dec.)
    unsigned int num2 = 0x39;   //  111001  - 57 (dec.)
    
    unsigned int bit_res1 = num1 & num2;
    unsigned int log_res1 = num1 && num2;

    printf("(bitwise) 0x%x & 0x%x = 0x%x\n", num1, num2, bit_res1);
    printf("(logical) 0x%x && 0x%x = 0x%x\n", num1, num2, log_res1);

    return(EXIT_SUCCESS);
}

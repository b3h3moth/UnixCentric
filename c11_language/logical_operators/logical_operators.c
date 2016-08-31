#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Gli operatori logici in C sono: '||' (OR), '&&' (AND) e '!' (NOT), essi
    restituiscono 1 (TRUE) o 0 (FALSE) e non devono essere confusi con gli
    operatori bitwise. */

    unsigned int num1 = 0x66;   // 01100110
    unsigned int num2 = 0x39;   // 00111001
    
    unsigned int bit_res1 = num1 & num2;
    unsigned int log_res1 = num1 && num2;
    unsigned int bit_res2 = num1 | num2;
    unsigned int log_res2 = num1 || num2;
    unsigned int bit_res3 = ~num1 | ~num2;
    unsigned int log_res3 = !num1 || !num2;
    unsigned int bit_res4 = num1 & !num2;
    unsigned int log_res4 = num1 && ~num2;

    printf("(bitwise)  0x%x  &  0x%x = 0x%x\n", num1, num2, bit_res1);
    printf("(logical)  0x%x &&  0x%x = 0x%x\n", num1, num2, log_res1);
    printf("(bitwise)  0x%x  |  0x%x = 0x%x\n", num1, num2, bit_res2);
    printf("(logical)  0x%x ||  0x%x = 0x%x\n", num1, num2, log_res2);
    printf("(bitwise) ~0x%x |  ~0x%x = 0x%x\n", num1, num2, bit_res3);
    printf("(logical) !0x%x || !0x%x = 0x%x\n", num1, num2, log_res3);
    printf("(bitwise)  0x%x  & !0x%x = 0x%x\n", num1, num2, bit_res4);
    printf("(logical)  0x%x && ~0x%x = 0x%x\n", num1, num2, log_res4);

    return(EXIT_SUCCESS);
}

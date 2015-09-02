#include <stdio.h>
#include <stdlib.h>

void bit_swap(int *x, int *y);

int main(void) {
    unsigned char num_a = 0; // binario: 00000000
    unsigned char num_b = 1;
    unsigned char num_c = 10;

    // ~
    // One's complement operator (Operatore di completamento a uno)
    // inverte tutti i bit dell'operando su cui agisce
    unsigned char res_not = ~num_a; // binario 11111111;

    unsigned char and_num = num_b & num_c;
    unsigned char or_num = num_b | num_c;
    unsigned char xor_num = num_b ^ num_c;

    printf("(~) ~num(%d) = hex:0x%x - dec.: %d\n", num_a, res_not, res_not);
    printf("(AND) %d & %d = %d - hex.0x%x\n", num_b, num_c, and_num, and_num);
    printf(" (OR) %d | %d = %d - hex.0x%x\n", num_b, num_c, or_num, or_num);
    printf("(XOR) %d ^ %d = %d - hex.0x%x\n", num_b, num_c, xor_num, xor_num);

    return(EXIT_SUCCESS);
}

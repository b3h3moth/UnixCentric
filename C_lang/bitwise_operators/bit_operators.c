#include <stdio.h>
#include <stdlib.h>

void bit_swap(int *x, int *y);

int main(void) {
    unsigned char num_a = 0; // binario: 00000000
    unsigned char num_c = 1;
    unsigned char num_b = 10;

    // ~
    // One's complement operator (Operatore di completamento a uno)
    // inverte tutti i bit dell'operando su cui agisce
    unsigned char res_not = ~num_a; // binario 11111111;

    unsigned char and_num = num_c & num_b;
    unsigned char or_num = num_c | num_b;
    unsigned char xor_num = num_c ^ num_b;

    printf("(NOT) ~num(%4d) = hex:0x%x - dec.: %d\n", num_a, res_not, res_not);
    printf("(AND) num_c(0x%x) & num_b(0x%x) = 0x%x\n", num_c, num_b, and_num);
    printf(" (OR) num_c(0x%x) | num_b(0x%x) = 0x%x\n", num_c, num_b, or_num);
    printf("(XOR) num_c(0x%x) ^ num_b(0x%x) = 0x%x\n", num_c, num_b, xor_num);

    return(EXIT_SUCCESS);
}

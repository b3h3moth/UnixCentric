#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num = 0x00000000;
    int num_a = 0x1010;
    int num_b = 0x1111;
    int not_num = ~num;
    int and_num = num_a & num_b;
    int or_num = num_a | num_b;
    int xor_num = num_a ^ num_b;

    printf("(NOT) ~num(0x%x) = 0x%x\n", num, not_num);
    printf("(AND) num_a(0x%x) & num_b(0x%x) = 0x%x\n", num_a, num_b, and_num);
    printf(" (OR) num_a(0x%x) | num_b(0x%x) = 0x%x\n", num_a, num_b, or_num);
    printf("(XOR) num_a(0x%x) ^ num_b(0x%x) = 0x%x\n", num_a, num_b, xor_num);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num = 0x00;
    int not_num = ~num;
    int num_a = 0x1010;
    int num_b = 0x1111;
    int and_num_ab = num_a & num_b;

    printf("num: 0x%x, %d (dec)\n", num, num);
    printf("~num(0x%x), %d (dec)\n", not_num, not_num);
    printf("num_a(0x%x) & num_b(0x%x) = 0x%x\n", num_a, num_b, and_num_ab);

    return(EXIT_SUCCESS);
}

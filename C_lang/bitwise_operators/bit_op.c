#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num = 0x00;
    int not_num = ~num;
    int and_num = 0x1011 & 0x0010;

    printf(" num: 0x%x, %d (dec)\n", num, num);
    printf("~num: 0x%x, %d (dec)\n", not_num, not_num);
    printf("0x1011 & 0x0010 = 0x%x, %d (dec)\n", and_num, and_num);

    return(EXIT_SUCCESS);
}

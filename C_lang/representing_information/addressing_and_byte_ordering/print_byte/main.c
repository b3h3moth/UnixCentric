#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

int main(void) {
    char c = 'A';
    int num = 123456;

    print_bit( (unsigned char *)&c, sizeof(char));
    print_byte( (unsigned char *)&c, sizeof(char));

    print_bit( (unsigned char *)&num, sizeof(int));
    print_byte( (unsigned char *)&num, sizeof(int));
    return(EXIT_SUCCESS);
}

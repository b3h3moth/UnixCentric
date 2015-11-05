#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

int main(void) {
    char c = 'A';

    print_bit( (unsigned char *)&c, sizeof(char));

    return(EXIT_SUCCESS);
}

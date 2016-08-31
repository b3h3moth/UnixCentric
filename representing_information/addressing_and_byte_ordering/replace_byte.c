#include <stdio.h>
#include <stdlib.h>

unsigned replace_byte(unsigned def_num, int byte_pos, char new_byte) {
    int shift = byte_pos << 3;
    unsigned mask = 0xFF << shift;
    return (def_num & ~mask) | (new_byte << shift);
}

int main(void) {
    unsigned default_number = 0x11111111;
    char value = 0xEF;

    for (int i=0; i<4; i++) {
        unsigned result = replace_byte(default_number, i, value);
        printf("%#x\n", result);
    }

    return(EXIT_SUCCESS);
}

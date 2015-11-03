#include <stdio.h>
#include <stdlib.h>

unsigned replace_byte(unsigned def_num, int byte_pos, char new_byte) {
    int shift = byte_pos << 3;
    unsigned mask = 0xFF << shift;
    return (def_num & ~mask) | (new_byte << shift);
}

int main(void) {
    unsigned default_number = 0x11223344;
    char value = 0xDD;
    unsigned result = replace_byte(default_number, 2, value);

    printf("%#x\n", result);

    return(EXIT_SUCCESS);
}

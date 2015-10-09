#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Lo scopo del programma e' di inserire 4 caratteri da un byte ciascuno in un
intero da 32 bit, ovvero 4 byte */

int pack_char(char cha, char chb, char chc, char chd);
void print_bit(int val);

int main(void) {
    printf("abcd= ");
    print_bit(pack_char('l', 'u', 'c', 'a'));

    return(EXIT_SUCCESS);
}

int pack_char(char cha, char chb, char chc, char chd) {
    int integer_val = cha;

    integer_val = (integer_val << CHAR_BIT) | chb;
    integer_val = (integer_val << CHAR_BIT) | chc;
    integer_val = (integer_val << CHAR_BIT) | chd;

    return integer_val;
}

void print_bit(int val) {
    int size = sizeof(val);
    int bit_val = size * CHAR_BIT;
    int mask = 1 << (bit_val - 1); // Work on Most Significant Bit

    printf("%d byte - %d bit\n", size, bit_val);

    for (int i=1; i<=bit_val; ++i) {

        // Print 0 if MSB (Most Significant Bit) is 0, 1 otherwise
        (val & mask) == 0 ? printf("0") : printf("1");

        val <<= 1;

        // Print 8 bit then add a space
        if ((i % 8 == 0) && (i != 0))
            printf(" ");
    }
}

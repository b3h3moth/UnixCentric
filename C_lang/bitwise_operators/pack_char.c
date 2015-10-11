#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* Lo scopo del programma e' di inserire 4 caratteri da un byte ciascuno in un
intero da 32 bit, ovvero 4 byte */

int pack_char(char cha, char chb, char chc, char chd);
void print_bit(int val);
int pack(char str[]);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <4 characters>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("%8c %8c %8c %8c\n", argv[1][0], argv[1][1], argv[1][2], argv[1][3]);
    puts("");
    print_bit(pack(argv[1]));
    return(EXIT_SUCCESS);
}

int pack_char(char cha, char chb, char chc, char chd) {
    int integer_val = cha;

    integer_val = (integer_val << CHAR_BIT) | chb;
    integer_val = (integer_val << CHAR_BIT) | chc;
    integer_val = (integer_val << CHAR_BIT) | chd;

    return integer_val;
}

int pack_char_compact(char str[]) {
    int val = str[0];

    for (int i=0; i<strlen(str); i++)
        val = (val << CHAR_BIT) | str[i];

    return val;
}

void print_bit(int val) {
    int size = sizeof(val);
    int bit_val = size * CHAR_BIT;
    int mask = 1 << (bit_val - 1); // Work on Most Significant Bit

    for (int i=1; i<=bit_val; ++i) {

        // Print 0 if MSB (Most Significant Bit) is 0, 1 otherwise
        putchar((val & mask) == 0 ? ('0') : ('1'));

        val <<= 1;

        // Print 8 bit then add a space
        if ((i % 8 == 0) && (i != 0))
            putchar(' ');
    }
}

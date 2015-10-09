#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Lo scopo del programma e' di inserire 4 caratteri da un byte ciascuno in un
intero da 32 bit, ovvero 4 byte */

int pack_char(char cha, char chb, char chc, char chd);

int main(void) {
    return(EXIT_SUCCESS);
}

int pack_char(char cha, char chb, char chc, char chd) {
    int integer_val = cha;

    integer_val = (integer_val << CHAR_BIT) | chb;
    integer_val = (integer_val << CHAR_BIT) | chc;
    integer_val = (integer_val << CHAR_BIT) | chd;

    return integer_val;
}

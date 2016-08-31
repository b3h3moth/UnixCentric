#include <stdio.h>
#include <stdlib.h>

int foo(unsigned word);
int bar(unsigned word);

int main(void) {
    unsigned val1 = 0x00000076;
    unsigned val2 = 0x87654321;
    unsigned val3 = 0x000000c9;
    unsigned val4 = 0xEDCBA987;

    printf("%10s %12s\n", "foo()", "bar()");
    printf("%#.8x - %#.8x\n", foo(val1), bar(val1));
    printf("%#.8x - %#.8x\n", foo(val2), bar(val2));
    printf("%#.8x - %#.8x\n", foo(val3), bar(val3));
    printf("%#.8x - %#.8x\n", foo(val4), bar(val4));

    return(EXIT_SUCCESS);
}

int foo(unsigned word) {
    // bit gestiti logicamente
    return (int) ((word << 24) >> 24);
}

int bar(unsigned word) {
    // bit gestiti aritmeticamente
    return ((int) word << 24) >> 24;
}

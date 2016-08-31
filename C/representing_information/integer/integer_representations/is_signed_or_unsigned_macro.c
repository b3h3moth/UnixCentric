#include <stdio.h>
#include <stdlib.h>

#define IS_UNSIGNED(val) (val >= 0 && ~val >= 0)
#define IS_SIGNED(type) ((type)0 - 1 > 0)

int main(void) {
    signed int      val = -10;

    if (IS_UNSIGNED(val) == 1)
        puts("unsigned int");
    else
        puts("signed int");

    if (IS_SIGNED(unsigned int) == 1)
        puts("unsigned int");
    else
        puts("signed int");

    return(EXIT_SUCCESS);
}

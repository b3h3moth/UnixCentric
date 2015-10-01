#include <stdio.h>
#include <stdlib.h>

int foo(unsigned word);
int bar(unsigned word);

int main(void) {
    return(EXIT_SUCCESS);
}

int foo(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int bar(unsigned word) {
    return ((int) word << 24) >> 24;
}

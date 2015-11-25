#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned char uch = 0xFF;
    char ch = 0xFF;

    // Which is the result? Are you sure?
    int val = (uch == ch);

    printf("Result is: %d\n", val);

    return(EXIT_SUCCESS);
}

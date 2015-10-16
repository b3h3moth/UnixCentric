#include <stdio.h>
#include <stdlib.h>

/* Warning: Binary integer literals are a GNU extension

Una costante binaria puo' essere scritta utilizzando il prefisso 
'0b' oppure '0B', non e' tuttavia parte di alcuno standard */

int main(void) {
    int val1 = 0B00000001; // 1
    int val2 = 0b00000010; // 2
    int total = val1 + val2;
    int val3 = 0xF;
    int val4 = 0b00001111;

    printf("%d + %d = %d\n", val1, val2, total);

    if (val3 == val4)
        printf("They are both %d\n", val4);

    return(EXIT_SUCCESS);
}

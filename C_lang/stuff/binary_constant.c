#include <stdio.h>
#include <stdlib.h>

/* Warning: Binary integer literals are a GNU extension

Una costante binaria puo' essere scritta utilizzando il prefisso 
'0b' oppure '0B', non e' tuttavia parte di alcuno standard */

int main(void) {
    int x = 0B00000001; // 1
    int y = 0b00000010; // 2
    int z = x + y;

    printf("%d + %d = %d\n", x, y , z);

    return(EXIT_SUCCESS);
}

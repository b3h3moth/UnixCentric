#include <stdio.h>
#include <stdlib.h>

/* Una costante binaria puo' essere scritta in GCC utilizzando il prefisso 
'0b' oppure '0B' */

int main(void) {
    int x = 0B00000001; // 1
    int y = 0b00000010; // 2
    int z = x + y;

    printf("%d + %d = %d\n", x, y , z);

    return(EXIT_SUCCESS);
}

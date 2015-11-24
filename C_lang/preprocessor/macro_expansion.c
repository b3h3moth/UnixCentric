#include <stdio.h>
#include <stdlib.h>

/* Si utilizza la compilazione condizionale per inserire una macro.

$ gcc -std=c11 -Wall -pedantic -DNUM file.c
$ gcc -std=c11 -Wall -pedantic -DNUM=10 file.c

*/
int main(void) {

#ifdef NUM
    for (int i=NUM; i>0; i--)
        printf("%d, ", i);
    printf("\n");
#endif

    printf("Hello");

    return(EXIT_SUCCESS);
}

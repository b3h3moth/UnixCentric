#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' di verificare quanta memoria, espressa in Mb,
puo' essere allocata in un processo */

int main(void) {
    int mb = 0;

    while (malloc(1<<20))
        ++mb;

    printf("Allocated %d Mb\n", mb);

    return(EXIT_SUCCESS);
}

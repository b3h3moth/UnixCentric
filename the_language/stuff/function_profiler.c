#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOOP    10000000
// Lo scopo del programma e' di calcolare il tempo di esecuzione di un ciclo

int main(void) {
    clock_t before;
    double after;

    before = clock();
    for (int i=0; i<MAX_LOOP; i++)
        ;
    after = clock()  - before;
    
    printf("for loop of \'%d\' elements used \'%f\' seconds.\n", \
            MAX_LOOP, after/CLOCKS_PER_SEC);

    return(EXIT_SUCCESS);
}

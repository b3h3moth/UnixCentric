#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    clock_t before;
    double elapsed;

    before = clock();
    system("ls -l");
    elapsed = clock()  - before;
    printf("function used %.3f seconds\n", elapsed/CLOCKS_PER_SEC);
    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

extern char etext, edata, end;
int main(void) {
    printf("%x %x %x\n", (int)&etext, (int)&edata, (int)&end);
    return(EXIT_SUCCESS);
}

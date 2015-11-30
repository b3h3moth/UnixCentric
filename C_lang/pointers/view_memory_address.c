#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

int main(void) {
    unsigned int addr;
    int i, n;
    BYTE *ptr;
    char str_addr[] = "Address of";

    printf("%9s %5s %#x\n", str_addr, "main", (unsigned int) main);
    printf("%9s %5s %#x\n", str_addr, "addr", (unsigned int) &addr);
    
    return(EXIT_SUCCESS);
}

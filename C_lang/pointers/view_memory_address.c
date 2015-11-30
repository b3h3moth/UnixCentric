#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

int main(void) {
    unsigned int addr;
    int i, nbyte;
    BYTE *ptr;
    char str_addr[] = "Address of";

    printf("%9s %5s %#x\n", str_addr, "main", (unsigned int) main);
    printf("%9s %5s %#x\n", str_addr, "addr", (unsigned int) &addr);

    printf("\nHexadecimal address: ");
    scanf("%x", &addr);
#ifdef ADDRESS
    printf("%#x\n", addr);
#endif
    printf("How many bytes: ");
    scanf("%x", &nbyte);

    printf("%10s %20s %20s", "Address", "Byte", "Characters");

    return(EXIT_SUCCESS);
}

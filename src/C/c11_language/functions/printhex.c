#include <stdio.h>
#include <stdlib.h>

void printhex(void *p, int size);

int main(void) {
    float f = -317.125;
    int i = -1013018624;
    char c = 'A';
    double d = 1.2345e-14;

    printf("Value:%12f - hex: ", f); printhex(&f, sizeof(f));
    printf("Value:%12d - hex: ", i); printhex(&i, sizeof(i));
    printf("Value:%12c - hex: ", c); printhex(&c, sizeof(c));
    printf("Value:%12g - hex: ", d); printhex(&c, sizeof(d));

    return(EXIT_SUCCESS);
}

/* It prints each actual parameter like an hex number */
void printhex(void *p, int size) {
    /* A pointer to void can't be used in expressions, so the best
     way to print a memory address is a cast, one byte at a time */
    unsigned char *ip = (unsigned char *)p;   /* First byte address */

    printf("0x");
    for (int i=size-1; i>=0; i--) {
        printf("%02x", *(ip + i) );
    }
    printf("\n");
}

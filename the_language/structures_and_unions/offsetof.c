#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* 
HEADER: <stddef.h>
MACRO : size_t offsetof(type, member);

La macro offsetof richiede due argomenti, il tipo di una struttura 'type' e un
mebro della struttura 'member', lo scopo e' di calcolare il numero di byte - 
l'offset ovviamente - tra l'inizio della struttura e il membro designato. */

struct data {
    char c;
    short s;
    int vec[4];
    float f;
    double d;
};

typedef struct data data;

int main(void) {
    /* Il primo membro della struttura, poiche' corrisponde all'indirizzo della
    struttura stessa, dovrebbe avere offset pari a 0 */
    printf("%2d is the offset 1st member (char c)\n", offsetof(data, c));
    printf("%2d is the offset 2nd member (short s)\n", offsetof(data, s));
    printf("%2d is the offset 3rd member (int vec[4])\n", offsetof(data, vec));
    printf("%2d is the offset 4th member (float f)\n", offsetof(data, f));
    printf("%2d is the offset 5th member (double d)\n", offsetof(data, d));

    return(EXIT_SUCCESS);
}

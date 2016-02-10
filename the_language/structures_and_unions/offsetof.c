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
    printf("%d offset first member (char c)\n", offsetof(data, c));
    printf("%d offset second member (short s)\n", offsetof(data, s));
    printf("%d offset third member (int vec[4])\n", offsetof(data, vec));
    printf("%d offset fourth member (float d)\n", offsetof(data, f));

    return(EXIT_SUCCESS);
}

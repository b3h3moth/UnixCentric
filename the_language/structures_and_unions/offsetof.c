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
    union {
        int ua;
        int ub;
        int uc;
        int ud;
    } type;
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

    // Si puo' calcolare l'offset anche degli elementi di un vettore
    printf("%2d is the offset of (int vec[0])\n", offsetof(data, vec[0]));
    printf("%2d is the offset of (int vec[1])\n", offsetof(data, vec[1]));
    printf("%2d is the offset of (int vec[2])\n", offsetof(data, vec[2]));
    printf("%2d is the offset of (int vec[3])\n", offsetof(data, vec[3]));

    printf("%2d is the offset of (union int ua)\n", offsetof(data, type.ua));
    printf("%2d is the offset of (union int ub)\n", offsetof(data, type.ub));
    printf("%2d is the offset of (union int uc)\n", offsetof(data, type.uc));
    printf("%2d is the offset of (union int ud)\n", offsetof(data, type.ud));


    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

struct st {
    char    a;
    double  b;
    char    c;
} newst = {'x', 2.0, 'y'};

/* 10 byte e' la somma del peso di ciascun membro, il compilatore tuttavia
allochera' per l'intera struttura 24 byte, ben 14 byte in piu'. Perche'?

Il compilatore alloca la memoria necessaria a contenere ciascun membro, ma in 
caso di non allineamento fara' riferimento al tipo piu' grande dei membri, in
questo caso un double da 8 byte. 

Pertanto la memoria allocata nel caso specifico e':
8 byte per un char   +
8 byte per il double +
8 byte per un char   =
24 byte              

Se al posto del double ci fosse stato un int, il compilatore avrebbe allocato
12 byte, se ci fosse stato uno short i byte sarebbero stati 6 e cosi via. */

int main(void) {
    printf("sizeof structure: %d\n", sizeof(newst));

    return(EXIT_SUCCESS);
}

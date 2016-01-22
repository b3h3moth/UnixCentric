#include <stdio.h>
#include <stdlib.h>

#define VEC_SIZE(x) (sizeof(x)/sizeof(x[0]))
enum { 
    A = 127,
    M = 96
};

unsigned int hash(char *str);

int main(void) {
    char *strings[] = { "take", "a", "walk", "on", "the", "wild", "side" };
    
    for (int i=0; i<VEC_SIZE(strings); i++)
        printf("hash of \'%4s\' is: %u\n", strings[i], hash(strings[i]));

    return(EXIT_SUCCESS);
}

// Tipica funzione hash per le stringhe
unsigned int hash(char *str) {
    unsigned char *p;
    int h = 0;

    for (p = (unsigned char *)str; *p != '\0'; p++)
        h = (A * h + *p) % M;

    return h;
}


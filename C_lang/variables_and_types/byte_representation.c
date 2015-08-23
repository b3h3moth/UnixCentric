#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Lo scopo del programma e' di fornire la 'byte representation' di differenti
    programmi oggetto 
*/

typedef unsigned char *byte_pointer;

// Fornisce ciascun byte in esadecimale
void show_bytes(byte_pointer start, int len) {
    int i;
    for (i=0; i<len; i++) {
        printf(" %.2x", start[i]);
    }
    printf(" (%d byte)\n", len);
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main(void) {

    return(EXIT_SUCCESS);
}

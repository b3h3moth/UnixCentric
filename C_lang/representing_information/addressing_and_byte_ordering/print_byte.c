#include <stdio.h>
#include <limits.h>

void print_byte(int num);

/* Stampa un vettore di interi in esadecimali, a coppie di byte; si assume 
l'ordinamento dei byte stessi essere little-endian */

int main(void) {
    unsigned numbers[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
        20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
        41,42,43,44,45,46,47,48,49,50};

    for(int i=1; i<sizeof(numbers)/sizeof(numbers[0]); i++) {
        printf("%7d: ", i*i*i);
        print_byte(i*i*i);
        printf("\n");
    }
}

void print_byte(int num) {
    unsigned    n_characters;
    unsigned    n_bit;          // Il numero dei bit
    unsigned    mask;
    int         ch;

    n_characters = sizeof(int);
    n_bit        = n_characters * CHAR_BIT;
    mask         = 0xFF << (n_bit - CHAR_BIT);  // 0xFF000000

    for (ch=0; ch<n_characters; ++ch) {
        printf("%02x ", (unsigned) (num & mask) >> (n_bit - CHAR_BIT));
        num <<= CHAR_BIT;
    }
}

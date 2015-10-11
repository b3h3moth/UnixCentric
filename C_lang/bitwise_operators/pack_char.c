#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* Lo scopo del programma e' di inserire 4 caratteri da un byte ciascuno in un
intero da 32 bit, ovvero 4 byte */

int pack_char(char cha, char chb, char chc, char chd);
int pack_char_compact(char str[]);
void print_bit(int val);

int main(int argc, char *argv[]) {

    if ( (argc < 2) || (strlen(argv[1]) > 4) ) {
        fprintf(stderr, "Usage: %s <4 characters>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Stampa un carattere alla volta la stringa ottenuta come argomento
    printf("%8c%9c%9c%9c\n", argv[1][0], argv[1][1], argv[1][2], argv[1][3]);
    
    print_bit(pack_char(argv[1][0], argv[1][1], argv[1][2], argv[1][3]));
    printf("\n");
    print_bit(pack_char_compact(argv[1]));

    return(EXIT_SUCCESS);
}

/* La funzione pack_char() salva esattamente 4 caratteri da 1 byte ciascuno 
in un intero da 4 byte */
int pack_char(char cha, char chb, char chc, char chd) {
    // Salva il primo carattere negli ultimi 8 bit meno significativi
    int integer_val = cha;

    /* Scorrimento a sinistra (left-shift) di CHAR_BIT (8 bit) degli ultimi 
    8 bit meno significativi, dopodiche' salva il nuovo carattere */
    integer_val = (integer_val << CHAR_BIT) | chb;
    integer_val = (integer_val << CHAR_BIT) | chc;
    integer_val = (integer_val << CHAR_BIT) | chd;

    return integer_val;
}

// Versione compatta della funzione pach_char() 
int pack_char_compact(char str[]) {
    int val = str[0];

    for (int i=0; i<strlen(str); i++)
        val = (val << CHAR_BIT) | str[i];

    return val;
}

void print_bit(int val) {
    int size = sizeof(val);
    int bit_val = size * CHAR_BIT;
    int mask = 1 << (bit_val - 1); // Work on Most Significant Bit

    for (int i=1; i<=bit_val; ++i) {

        // Print 0 if MSB (Most Significant Bit) is 0, 1 otherwise
        putchar((val & mask) == 0 ? ('0') : ('1'));

        val <<= 1;

        // Print 8 bit then add a space
        if ((i % 8 == 0) && (i != 0))
            putchar(' ');
    }
}

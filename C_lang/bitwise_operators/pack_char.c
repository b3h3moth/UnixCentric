#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* Lo scopo del programma e' di inserire 4 caratteri da un byte ciascuno in un
intero da 32 bit, ovvero 4 byte mediante la funzione pack_char(), dopodiche'
eseguire l'azione opposta mediante la funzione unpack_char_char(), ovvero estrarre
un byte */

int pack_char(char cha, char chb, char chc, char chd);
int pack_char_compact(char str[]);
char unpack_char(int integer, int character);
void print_bit(int val);

int main(int argc, char *argv[]) {

    if ( (argc < 2) || (strlen(argv[1]) > 4) ) {
        fprintf(stderr, "Usage: %s <4 characters>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Stampa un carattere alla volta la stringa ottenuta come argomento
    printf("%8c%9c%9c%9c\n", argv[1][0], argv[1][1], argv[1][2], argv[1][3]);
    
    // print_bit(pack_char(argv[1][0], argv[1][1], argv[1][2], argv[1][3]));
    // printf("\n");

    print_bit(pack_char_compact(argv[1]));

    int value = pack_char('c', 'h', 'a', 'r');
    printf("unpack integer, get the second byte: ");
    printf("The second byte is: %c\n", unpack_char(value, 1));

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

// La funzione unpack_char() scompatta un byte da int
char unpack_char(int stored_integer, int byte_to_get) {
    int      size = byte_to_get * CHAR_BIT;  // byte_to_get = 0,1,2,3
    unsigned mask = 255; // 00000000 00000000 00000000 11111111

    /* Scorrimento a sinistra (left-shift) di 'size' bit (0,8,16 o 24), ovvero
    gli 8 bit del byte meno significativo, in modo tale da eseguire 
    successivamente lo scompattamento */
    mask <<= size;

    /* Ritorna il byte indicato da byte_to_get
    Anzitutto si recupera un valore da un campo di bit mediante una maschera,
    dopodiche' il byte risultante sara' spostato con uno scorrimento a destra 
    (right-shift) negli ultimi 8 bit e, poiche' il tipo di dato di ritorno
    della funzione e' un char, tali bit (1 byte) sono esattamente cio' che 
    serve */
    return ((stored_integer & mask) >> size);
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

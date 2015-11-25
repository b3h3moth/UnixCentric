#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Nuovo tipo 'word_bytes' che definisce i 4 byte di una word da 32 bit
typedef struct {
    unsigned byte0: 8;
    unsigned byte1: 8;
    unsigned byte2: 8;
    unsigned byte3: 8;
} word_bytes;

// Nuovo tipo 'word_bit' che definisce i 32 bit di una word
typedef struct {
    unsigned  bit0: 1,  bit1: 1,  bit2: 1,  bit3: 1,  bit4: 1,  bit5: 1,   \
              bit6: 1,  bit7: 1,  bit8: 1,  bit9: 1, bit10: 1, bit11: 1,   \
             bit12: 1, bit13: 1, bit14: 1, bit15: 1, bit16: 1, bit17: 1,   \
             bit18: 1, bit19: 1, bit20: 1, bit21: 1, bit22: 1, bit23: 1,   \
             bit24: 1, bit25: 1, bit26: 1, bit27: 1, bit28: 1, bit29: 1,   \
             bit30: 1, bit31: 1;
} word_bit;

// Nuovo tipo 'word' che definisce una parola da 4 byte (32 bit)
typedef union {
    int         integer;
    word_bit    bit;
    word_bytes  byte;
} Word;

// Prototipo della funzione print_bit()
void print_bit(int num);

int main(void) {
    // Settaggio di tutti e 32 i bit a 0
    Word word = {0};

    // Settaggio degli ultimi 8 bit necessari a formare l'intero 255
    printf("Set the last eight bit to get an integer: '255'\n");
    
    word.bit.bit24 = word.bit.bit25 = word.bit.bit26 = word.bit.bit27 = \
                     word.bit.bit28 = word.bit.bit29 = word.bit.bit30 = \
                     word.bit.bit31 = 1;
    print_bit(word.integer);

    // Al fine di ottenere l'intero 255, lo si salva nell'ultimo byte
    printf("\n\nSet the last byte to get integer: '255'\n");

    word.byte.byte3 = 255;
    print_bit(word.integer);

    // Si salva il valore 255 direttamente nell'intero
    printf("\n\nSet the integer value: '255'\n");
    
    word.integer = 255;
    print_bit(word.integer);
    
    return(EXIT_SUCCESS);
}

// La funzione print_bit() stampa ciascun bit dell'intero 'num'
void print_bit(int num) {
    int bit_size = sizeof(int) * CHAR_BIT;
    int mask = 1 << (bit_size -1);

    for (int i=1; i<=bit_size; i++) {
        (num & mask) == 0 ? fputc('0',stdout) : fputc('1', stdout);

        num <<= 1;

        // Uno spazio ogni 8 bit
        if (i % CHAR_BIT == 0 && i < bit_size)
            fputc(' ', stdout);
    }
}

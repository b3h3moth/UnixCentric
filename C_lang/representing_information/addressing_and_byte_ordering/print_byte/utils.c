#include <stdio.h>
#include <limits.h>

/* Per stampare correttamente i dati binari ed esadecimali e' necessario
verificare il byte-ordering, ovvero se l'architettura e' di tipo little-endian,
big-endian oppure ne' l'una ne' l'altra */
#if BYTE_ORDER == LITTLE_ENDIAN

#define FIRST_CHAR(ptr, size)   (ptr + size - 1)
#define NEXT_CHAR(ptr)        --(ptr)

#elif BYTE_ORDER == BIG_ENDIAN

#define FIRST_CHAR(ptr, size)   (ptr)
#define NEXT_CHAR(ptr)        ++(ptr)

#endif

static void print_bit_char(unsigned char character);

extern void print_bit(unsigned char *ptr, unsigned int size) {
    unsigned char *first_character;
    int            ch;

    first_character = FIRST_CHAR(ptr, size);
    
    for (ch=1; ch<=size; ++ch) {
        print_bit_char(*first_character);
        fputc(' ', stdout);
        NEXT_CHAR(first_character);
    }

    fputc('\n', stdout);
}

static void print_bit_char(unsigned char character) {
    int           bit;
    unsigned char mask = 1;   // mask = 00000001

    mask <<= (CHAR_BIT - 1);  // mask = 10000000

    for (bit=1; bit<= CHAR_BIT; ++bit) {
        fputc( ((character & mask) == 0) ? '0' : '1', stdout);
        character <<=  1;
    }
}

#undef FIRST_CHAR
#undef NEXT_CHAR

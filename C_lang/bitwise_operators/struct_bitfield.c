#include <stdio.h>
#include <stdlib.h>

// Nuovo tipo word_bytes che definisce i 4 byte di una word da 32 bit
typedef struct {
    unsigned byte0: 8;
    unsigned byte1: 8;
    unsigned byte2: 8;
    unsigned byte3: 8;
} word_bytes;

// Nuovo tipo word_bit che definisce i 32 bit di una word
typedef struct {
    unsigned  bit0: 1,  bit1: 1,  bit2: 1,  bit3: 1,  bit4: 1,  bit5: 1,   \
              bit6: 1,  bit7: 1,  bit8: 1,  bit9: 1, bit10: 1, bit11: 1,   \
             bit12: 1, bit13: 1, bit14: 1, bit15: 1, bit16: 1, bit17: 1,   \
             bit18: 1, bit19: 1, bit20: 1, bit21: 1, bit22: 1, bit23: 1,   \
             bit24: 1, bit25: 1, bit26: 1, bit27: 1, bit28: 1, bit29: 1,   \
             bit30: 1, bit31: 1;
} word_bit;

int main(void) {
    return(EXIT_SUCCESS);
}

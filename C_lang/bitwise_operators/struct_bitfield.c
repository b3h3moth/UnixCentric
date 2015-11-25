#include <stdio.h>
#include <stdlib.h>

// Nuovo tipo struct che definisce i 4 byte di una word da 32 bit
typedef struct {
    unsigned byte0: 8;
    unsigned byte1: 8;
    unsigned byte2: 8;
    unsigned byte3: 8;
} word_bytes;

int main(void) {
    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

int get_most_significant_byte(int num);

int main(void) {
    int number = 12345;

    int msb = get_most_significant_byte(number);
    printf("MSB od %d = %d\n", number, msb);

    return(EXIT_SUCCESS);
}

/* La funzione get_most_significant_byte() recuper il byte piu' significativo
di 'num' */
int get_most_significant_byte(int num) {
    // left-shift di word - 8
    int shift_val = (sizeof(int) - 1) << 3;

    // right-shift aritmetico
    int num_right = num >> shift_val;

    // Tutti i bit a 0 tranne il byte meno significativo (LSB)
    return num_right & 0xFF;
}

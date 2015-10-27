#include <stdio.h>
#include <stdlib.h>

int get_most_significant_byte(int num);

int main(void) {
    int numbers[] = {0xFFEEEEEE, 0xE1234567, 0x87654321, 0xAC00BC01,
                     0x1FAABBCC, 0x57894232, 0xD1678992, 0xEF00FFFF };

    unsigned int elem_of_numbers = sizeof(numbers) / sizeof(numbers[0]);

    for (int i=0; i<elem_of_numbers; i++) {
        int msb = get_most_significant_byte(numbers[i]);
        printf("MSB of %#X = %#X(%d)\n", numbers[i], msb, msb);
    }

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

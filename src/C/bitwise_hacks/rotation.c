#include <stdio.h>
#include <stdlib.h>

/* La funzione right_rotation() ruota 'n' bit verso destra, portandoli verso
i bit più significativi */
unsigned char right_rotation(unsigned char val, int n) {
    return (x >> n) | (x << 8 - n);
}

/* La funzione left_rotation() ruota 'n' bit verso sinistra, portandoli verso
i bit meno significativi */
unsigned char left_rotation(unsigned char val, int n) {
    return (x << n) | (x >> 8 - n);
}

int main(void) {
    return(EXIT_SUCCESS);
}

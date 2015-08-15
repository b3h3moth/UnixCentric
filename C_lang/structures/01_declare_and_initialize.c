#include <stdio.h>
#include <stdlib.h>

struct RGB_color {
    int read;
    int green;
    int blu;
};

int main(void) {

    /* Inizializza la struttura, ora sara' anche creato lo spazio di memoria
    necessario a contenere la variabile struct 'black' */
    struct RGB_color black = {0, 0, 0};

    return(EXIT_SUCCESS);
}

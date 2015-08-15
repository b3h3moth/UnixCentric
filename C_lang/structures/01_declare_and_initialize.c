#include <stdio.h>
#include <stdlib.h>

struct RGB_color {
    int set_red;
    int set_green;
    int set_blu;
};

int main(void) {

    /* Inizializza la struttura, ora sara' anche creato lo spazio di memoria
    necessario a contenere la variabile struct 'black' */
    struct RGB_color black = {0, 0, 0};

    struct RGB_color white;
    white.set_red = 255;
    white.set_green = 255;
    white.set_blu = 255;

    return(EXIT_SUCCESS);
}

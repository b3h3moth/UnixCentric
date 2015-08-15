#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RGB_color.h" /* Si include la definizione della struttura */

int main(void) {

    /* Dichiara ed inizializza la struttura subito dopo la definizione. 
    Sara' anche creato lo spazio di memoria necessario a contenere la 
    variabile struct 'black' */
    struct RGB_color black = {0, 0, 0, "nero"};

    /* Prima dichiara la variabile struct white, dopodiche' ciascun membro
    sara' inizializzato */
    struct RGB_color white;
    white.set_red = 255;
    white.set_green = 255;
    white.set_blu = 255;
    strncpy(white.set_name, "bianco", 6);

    return(EXIT_SUCCESS);
}

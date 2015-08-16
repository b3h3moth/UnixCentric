#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_01.h" /* Si include la definizione della struttura */

int main(void) {

    /* Dichiara ed inizializza la struttura subito dopo la definizione. 
    Sara' anche creato lo spazio di memoria necessario a contenere la 
    variabile struct 'black:
    
    Sintassi tradizionale: */
    struct RGB_color black = {0, 0, 0, "nero"};
    
    /*
    Sintassi GCC fino al primo standard (obsoleta):
    struct RGB_color gray = { set_red: 140,\
                              set_green: 140, \
                              set_blu: 140, \
                              set_name: "grigio" };

    Sintassi C99:
    struct RGB_color yellow = { .set_red   = 255,\
                                .set_green = 255,\
                                .set_blu   = 0,\
                                .set_name  = "giallo" };

    Prima dichiara la variabile struct white, dopodiche' ciascun membro
    sara' inizializzato */
    struct RGB_color white;
    white.set_red = 255;
    white.set_green = 255;
    white.set_blu = 255;
    strncpy(white.set_name, "bianco", 7);

    printf("%s: RGB(%i,%i,%i)\n", black.set_name, black.set_red, \
                                  black.set_green, black.set_blu);
    printf("%s: RGB(%i,%i,%i)\n", white.set_name, white.set_red, \
                                  white.set_green, white.set_blu);

    return(EXIT_SUCCESS);
}

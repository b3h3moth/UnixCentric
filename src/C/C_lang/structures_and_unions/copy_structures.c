#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rgb_color.h" /* definizione della struttura */

int main(void) {
    struct RGB_color white;
    struct RGB_color my_copy;

    // Inizializzazione della variabile di tipo struct RGB_color white
    white.set_red = 255;
    white.set_green = 255;
    white.set_blu = 255;
    strncpy(white.set_name, "bianco", 7); 

    /* Copia ciascun valore di 'white' in 'my_copy'. Operazione permessa
    perche' si tratta di strutture compatibili */
    my_copy = white;

    printf("%s: RGB(%i,%i,%i)\n", my_copy.set_name, my_copy.set_red, \
                                  my_copy.set_green, my_copy.set_blu);

    return(EXIT_SUCCESS);
}

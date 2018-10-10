#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rgb_color.h" /* Si include la definizione della struttura */

int main(void) {
    /* Una struttura (structure) e' caratterizzata da un insieme eterogeneo
    di elementi collocati sequenzialmente in memoria. Allorquando si dichiara
    non viene allocata memoria, cio' sara' fatto solo con la dichiarazione
    contestuale o successiva di una variabile del suo tipo.

    Si dichiara ed inizializza la struttura subito dopo la definizione. 
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

    Dichiara la variabile struct white, dopodiche' ciascun membro sara' 
    inizializzato.
    
    RGB_color e' il tag, indica un pattern che successivamente puo'
    essere utilizzato per dichiarare una variabile, ma non e' esso stesso una 
    variabile.  */
    struct RGB_color white;

    white.set_red = 255;
    white.set_green = 255;
    white.set_blu = 255;
    strncpy(white.set_name, "bianco", 7); /* E' un vettore, non basta inserire 
                                             la stringa; un carattere in più
                                             per il null character finale */

    // Si stampa in output il contenuto delle strutture
    // I commenti col doppio slash sono accettati da -std=c99 in poi
    printf("%s: RGB(%i,%i,%i)\n", black.set_name, black.set_red, \
                                  black.set_green, black.set_blu);

    printf("%s: RGB(%i,%i,%i)\n", white.set_name, white.set_red, \
                                  white.set_green, white.set_blu);

    return(EXIT_SUCCESS);
}

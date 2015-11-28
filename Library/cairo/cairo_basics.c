#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

#define WIDTH   250
#define HEIGHT  250

int main(void) {
    /* Quando si lavora con Cairo, per prima cosa e' necessario creare il
    Cairo context (un oggetto Cairo), che contiene tutti i parametri di stato 
    inerenti il disegno, dallo spessore della linea al colore, alla superficie
    su cui disegnare, etc..., 
    
    Il context e' sempre collegato ad una surface, e' di tipo 'cairo_t'
    La surface invece e' di tipo 'cairo_surface_t'
    
    Ci sono diversi tipi di surface, una per ogni formato supportato da Cairo,
    nel caso specifico si e' optato per una surface da WIDTH x HEIGHT px, con
    32 bit/px, colore RGB e Alpha */

    cairo_t         *cr;
    cairo_surface_t *surface;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    // Corpo del programma

    // Salvataggio del file, PNG
    cairo_surface_write_to_png(surface, image_name);

    // Rimozione del context, ovvero dell'oggetto Cairo
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

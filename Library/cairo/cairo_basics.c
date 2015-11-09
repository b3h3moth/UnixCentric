#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

#define WIDTH   150
#define HEIGHT  150

int main(void) {
    /* Quando si lavora con Cairo, per prima cosa e' necessario creare un
    Cairo context, che contiene tutti i parametri inerenti la grafica, dalla
    lunghezza della linea al colore, alla superficie su cui disegnare, etc., */
    cairo_t         *cr;
    cairo_surface_t *surface;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    // ...

    // Rimozione dell'oggetto creato
    cairo_destroy(cr);

    return(EXIT_SUCCESS);
}

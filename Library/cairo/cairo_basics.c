#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

#define WIDTH   800
#define HEIGHT  600

int main(void) {
    // Nuovo oggetto con una surface di 800x600 px, RGB32 con Alpha channel
    cairo_t         *cr_object;
    cairo_surface_t *surface;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr_object = cairo_create(surface);


    // Rimozione dell'oggetto creato
    cairo_destroy(cr_object);

    return(EXIT_SUCCESS);
}

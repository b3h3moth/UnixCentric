#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

#define WIDTH   150
#define HEIGHT  150

int main(void) {
    // Context con una surface di 800x600 px e RGB con Alpha channel
    cairo_t         *cr_object;
    cairo_surface_t *surface;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr_object = cairo_create(surface);

    // ...

    // Rimozione dell'oggetto creato
    cairo_destroy(cr_object);

    return(EXIT_SUCCESS);
}

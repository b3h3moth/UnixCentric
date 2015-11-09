#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

#define WIDTH   250
#define HEIGHT  250

int main(void) {
    cairo_t         *cr;
    cairo_surface_t *surface;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    /* Canale Alpna impostato ad 1, quindi disattivato.
    Istruzione equivalente a: cairo_set_source_rgb(cr, 0, 0, 0); */
    cairo_set_source_rgba(cr, 0, 0, 0, 1);

    cairo_move_to(cr, 120, 0);
    cairo_line_to(cr, 120, 250);
    cairo_set_line_width(cr, 10.0);

    cairo_stroke(cr);

    // Salvataggio del file, PNG
    cairo_surface_write_to_png(surface, "image.png");

    // Rimozione del context, ovvero dell'oggetto Cairo
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

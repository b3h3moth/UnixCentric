#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

#define WIDTH           320
#define HEIGHT          320

// Lo scopo del programma e' di disegnare una scacchiera

void draw_squares(cairo_t *cr, int rect_x, int rect_y);

int main(void) {
    cairo_t         *cr;
    cairo_surface_t *surface;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 1.0);

    // Spessore del tratteggio
    cairo_set_line_width(cr, 0.0);

    cairo_rectangle(cr, 40, 40, 240, 240);
    cairo_fill(cr);


    // Salvataggio del file, PNG
    cairo_surface_write_to_png(surface, "black_rectangle.png");

    // Rimozione del context, ovvero dell'oggetto Cairo
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

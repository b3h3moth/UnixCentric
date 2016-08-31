#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

#define WIDTH   320
#define HEIGHT  320

// Il disegno di 8 strisce verticali bianche e nere alternate

int main(void) {
    cairo_t         *cr;
    cairo_surface_t *surface;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    // Spessore delle linee
    cairo_set_line_width(cr, 40.0);

    // Linee bianche
    cairo_set_source_rgba(cr, 1.0, 1.0, 1.0, 1.0);
    cairo_move_to(cr, 20, 360);
    cairo_line_to(cr, 20, 0);
    cairo_move_to(cr, 100, 320);
    cairo_line_to(cr, 100, 0);
    cairo_move_to(cr, 180, 320);
    cairo_line_to(cr, 180, 0);
    cairo_move_to(cr, 260, 320);
    cairo_line_to(cr, 260, 0);
    cairo_stroke(cr);

    // Linee nere
    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 1.0);
    cairo_move_to(cr, 60, 320);
    cairo_line_to(cr, 60, 0);
    cairo_move_to(cr, 140, 320);
    cairo_line_to(cr, 140, 0);
    cairo_move_to(cr, 220, 320);
    cairo_line_to(cr, 220, 0);
    cairo_move_to(cr, 300, 320);
    cairo_line_to(cr, 300, 0);
    cairo_stroke(cr);

    // Salvataggio del file, PNG
    cairo_surface_write_to_png(surface, "image.png");

    // Rimozione del context, ovvero dell'oggetto Cairo
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

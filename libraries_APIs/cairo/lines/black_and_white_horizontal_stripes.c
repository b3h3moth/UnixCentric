#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

#define WIDTH   320
#define HEIGHT  320

// Il disegno di 8 strisce orizzontali bianche e nere alternate

int main(void) {
    cairo_t         *cr;
    cairo_surface_t *surface;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    // Spessore delle linee
    cairo_set_line_width(cr, 40.0);

    // Linee bianche
    cairo_set_source_rgba(cr, 1.0, 1.0, 1.0, 1.0);
    cairo_move_to(cr, 0, 300);
    cairo_line_to(cr, 320, 300);
    cairo_move_to(cr, 0, 220);
    cairo_line_to(cr, 320, 220);
    cairo_move_to(cr, 0, 140);
    cairo_line_to(cr, 320, 140);
    cairo_move_to(cr, 0, 60);
    cairo_line_to(cr, 320, 60);
    cairo_stroke(cr);

    // Linee nere
    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 1.0);
    cairo_move_to(cr, 0, 260);
    cairo_line_to(cr, 320, 260);
    cairo_move_to(cr, 0, 180);
    cairo_line_to(cr, 320, 180);
    cairo_move_to(cr, 0, 100);
    cairo_line_to(cr, 320, 100);
    cairo_move_to(cr, 0, 20);
    cairo_line_to(cr, 320, 20);
    cairo_stroke(cr);

    // Salvataggio del file, PNG
    cairo_surface_write_to_png(surface, "image.png");

    // Rimozione del context, ovvero dell'oggetto Cairo
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

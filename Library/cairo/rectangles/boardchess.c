#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

#define WIDTH           320
#define HEIGHT          320
#define SQUARE_WIDTH    40
#define SQUARE_HEIGHT   40

// Lo scopo del programma e' di disegnare una scacchiera

void draw_squares(cairo_t *cr, int rect_x, int rect_y);

int main(void) {
    cairo_t         *cr;
    cairo_surface_t *surface;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    // Spessore delle linee
    cairo_set_line_width(cr, 0.0);

    // 1° riga di quadrati bianchi
    cairo_set_source_rgba(cr, 1.0, 1.0, 1.0, 1.0);
    draw_squares(cr, 0, 0);
    // 1° riga di quadrati neri
    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 1.0);
    draw_squares(cr, 40, 0);

    // 2° riga di quadrati neri
    draw_squares(cr, 0, 40);
    // 2° riga di quadrati bianchi
    cairo_set_source_rgba(cr, 1.0, 1.0, 1.0, 1.0);
    draw_squares(cr, 40, 40);

    // Salvataggio del file, PNG
    cairo_surface_write_to_png(surface, "boardchess.png");

    // Rimozione del context, ovvero dell'oggetto Cairo
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

void draw_squares(cairo_t *cr, int rect_x, int rect_y) {
    for (int i=0; i<4; i++) {
        cairo_rectangle(cr, rect_x, rect_y, SQUARE_WIDTH, SQUARE_HEIGHT);
        cairo_fill(cr);
        rect_x += 80;
    }
}

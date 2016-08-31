#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

#define WIDTH   250
#define HEIGHT  250

// Il disegno di una linea orizzontale al centro dell'immagine

int main(void) {
    cairo_t         *cr;
    cairo_surface_t *surface;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    /* Setta la source del colore indicato (black) da R,G,B con il grado di
    opacita' Alpha settato a 1.0, ovvero equivalente a:
    cairo_set_source_rgb(cr, 0, 0, 0); */
    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 1.0);

    // Le coordinate di partenza
    cairo_move_to(cr, 0, 120);
    // Le coordinate di arrivo della linea
    cairo_line_to(cr, 250, 120);
    // Spessore della linea
    cairo_set_line_width(cr, 10.0);

    cairo_stroke(cr);

    // Salvataggio del file, PNG
    cairo_surface_write_to_png(surface, "image.png");

    // Rimozione del context, ovvero dell'oggetto Cairo
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

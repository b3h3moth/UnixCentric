#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cairo/cairo.h>

#define WIDTH   300
#define HEIGHT  200
#define POS_X   15.0
#define POS_Y   15.0
#define F_SIZE  14

int main(void) {
    cairo_surface_t *surface;
    cairo_t *cc;
    char image_name[] = "image.png";

    // Crea una surface di WIDTH x HEIGHT px e il cairo context
    surface = cairo_image_surface_create(CAIRO_FORMAT_RGB24, WIDTH, HEIGHT);
    cc = cairo_create(surface);

    // Settaggio del source al color bianco
    cairo_set_source_rgb(cc, 1, 1, 1);

    // Setta il font-type
    cairo_select_font_face(cc, "Monospace", CAIRO_FONT_SLANT_NORMAL, \
                                       CAIRO_FONT_WEIGHT_BOLD);
    // Setta il font-size a F_SIZE
    cairo_set_font_size(cc, F_SIZE);
    
    // Si sposta alla posizione POS_X, POS_Y per scrivere il testo
    cairo_move_to(cc, POS_X, POS_Y);
    cairo_show_text(cc, "Cairo 2D library");

    // Crea l'immagine PNG
    cairo_surface_write_to_png(surface, image_name);
    printf("Image created: %s\n", image_name);

    // Pulizia degli oggetti creati, rimozione di context e di surface.
    cairo_destroy(cc);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

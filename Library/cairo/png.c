#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cairo/cairo.h>

#define WIDTH   300
#define HEIGHT  200
#define F_SIZE  18

int main(void) {
    cairo_surface_t *surface;
    cairo_t *cr;
    char image_name[] = "image.png";

    // Crea una surface di WIDTH x HEIGHT px e il cairo context
    surface = cairo_image_surface_create(CAIRO_FORMAT_RGB24, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    // Settaggio del source al color bianco
    cairo_set_source_rgb(cr, 0.0, 0.70, 0.0);

    // Setta il font-type
    cairo_select_font_face(cr, "Monospace", CAIRO_FONT_SLANT_NORMAL, \
                                       CAIRO_FONT_WEIGHT_BOLD);
    // Setta il font-size a F_SIZE
    cairo_set_font_size(cr, F_SIZE);
    
    // Si sposta alla posizione specificata per scrivere il testo
    cairo_move_to(cr, 20.0, 20.0);
    cairo_show_text(cr, "PNG image");

    cairo_move_to(cr, 20.0, 100.0);
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_show_text(cr, "created with");

    cairo_move_to(cr, 20.0, 180.0);
    cairo_set_source_rgb(cr, 0.7, 0.2, 0.0);
    cairo_show_text(cr, "Cairo 2D graphic library");

    // Crea l'immagine PNG
    cairo_surface_write_to_png(surface, image_name);
    printf("Image created: %s\n", image_name);

    // Pulizia degli oggetti creati, rimozione di context e di surface.
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

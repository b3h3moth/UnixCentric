#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cairo/cairo.h>

#define WIDTH   300
#define HEIGHT  200
#define F_SIZE  18

/* Creazione di una immagine in formato PNG con scritte di colore verde, 
bianco e rosso. Il file risultante sara' image.png */

int main(void) {
    cairo_surface_t *surface;
    cairo_t *cr;
    char image_name[] = "image.png";

    /* Creazione del Cairo context, con una surface di WIDTH x HEIGHT px, con
    24 bit/px colore RGB */
    surface = cairo_image_surface_create(CAIRO_FORMAT_RGB24, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    // Setta il font-type
    cairo_select_font_face(cr, "Monospace", CAIRO_FONT_SLANT_NORMAL, \
                                       CAIRO_FONT_WEIGHT_BOLD);
    // Setta il font-size a F_SIZE
    cairo_set_font_size(cr, F_SIZE);
    
    /* Spostamento alla posizione specificata per scrivere il testo. Settaggio
    del source al color verde. Scrittura del testo */
    cairo_set_source_rgb(cr, 0.0, 0.70, 0.0);
    cairo_move_to(cr, 20.0, 20.0);
    cairo_show_text(cr, "PNG image");

    /* 80 pixel piu' in basso rispetto alla posizione precedente, relativa 
    all'asse y. Settaggio del source al color bianco. Scrittura del testo */
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_move_to(cr, 20.0, 100.0);
    cairo_show_text(cr, "created with");

    /* 100 pixel piu' in basso rispetto alla posizione precedente, relativa 
    all'asse y. Settaggio del source al color rosso. Scrittura del testo */
    cairo_move_to(cr, 20.0, 180.0);
    cairo_set_source_rgb(cr, 0.70, 0.0, 0.0);
    cairo_show_text(cr, "Cairo 2D graphic library");

    // Crea l'immagine PNG
    cairo_surface_write_to_png(surface, image_name);
    printf("Image created: %s\n", image_name);

    // Pulizia e rimozione del context (l'oggetto Cairo)
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

#define WIDTH   360
#define HEIGHT  360

// Il disegno di una linea verticale al centro dell'immagine

int main(void) {
    cairo_t         *cr;
    cairo_surface_t *surface;
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr = cairo_create(surface);

   
    // Spessore delle linee
    cairo_set_line_width(cr, 280.0);

    // Linee bianche
    cairo_set_source_rgba(cr, 1.0, 1.0, 1.0, 1.0);
    cairo_move_to(cr, 200, 360);
    cairo_line_to(cr, 200, 0);
    cairo_stroke(cr);

    cairo_set_line_width(cr, 40.0);

    // Linee nere
    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 1.0);
    cairo_move_to(cr, 40, 360);
    cairo_line_to(cr, 40, 0);
    cairo_move_to(cr, 120, 360);
    cairo_line_to(cr, 120, 0);
    cairo_move_to(cr, 200, 360);
    cairo_line_to(cr, 200, 0);
    cairo_move_to(cr, 280, 360);
    cairo_line_to(cr, 280, 0);
    cairo_stroke(cr);

    /*
    // Linee orizzontali nere
    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 1.0);
    cairo_move_to(cr, 20, 300);
    cairo_line_to(cr, 340, 300);
    cairo_stroke(cr);
*/
    cairo_set_source_rgba(cr, 1.0, 1.8, 1.0, 1.0);
    cairo_set_line_width(cr, 0.0);
    static int j=20; 
    for (int i=0; i<4; i++) {
        cairo_rectangle(cr, j, 40, 40, 40);
        cairo_fill(cr);
        j += 80;
    }
    
    cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 1.0);
    static int x=60; 
    for (int i=0; i<4; i++) {
        cairo_rectangle(cr, x, 40, 40, 40);
        cairo_fill(cr);
        x += 80;
    }
    // Salvataggio del file, PNG
    cairo_surface_write_to_png(surface, "image.png");

    // Rimozione del context, ovvero dell'oggetto Cairo
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

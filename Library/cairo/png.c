#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cairo/cairo.h>

#define SIZE 2048

int main(void) {
    cairo_surface_t *surface;
    cairo_t *cc;
    char image_name[] = "image.png";

    // Create surface (600x800 px) and cairo context
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 300, 300);
    cc = cairo_create(surface);

    // Black surface
    cairo_set_source_rgb(cc, 0, 0, 0);

    // Set font-type
    cairo_select_font_face(cc, "Sans", CAIRO_FONT_SLANT_NORMAL, \
                                       CAIRO_FONT_WEIGHT_NORMAL);
    // Set font-size
    cairo_set_font_size(cc, 15);
    
    // Move to 10.0, 10.0 position and drawing text
    cairo_move_to(cc, 1.0, 50.0);
    cairo_show_text(cc, "Cairo 2D library");

    // Create png image
    cairo_surface_write_to_png(surface, image_name);
    printf("Image created: %s\n", image_name);

    // Clean and destroy resources
    cairo_destroy(cc);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

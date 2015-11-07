#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>

int main(void) {
    cairo_surface_t *surface;
    cairo_t *cc;
    FILE *fd;

    fd = fopen("public.key", "r");

    // Create surface (400x600 px) and cairo context
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 400, 600);
    cc = cairo_create(surface);

    // Draw surface with a white background
    cairo_set_source_rgb(cc, 255, 255, 255);

    // Set font-type and font-size
    cairo_select_font_face(cc, "Sans", CAIRO_FONT_SLANT_NORMAL, \
                                       CAIRO_FONT_WEIGHT_NORMAL);

    // Move to 10.0, 10.0 position and drawing text
    cairo_move_to(cc, 10.0, 10.0);
    cairo_show_text(cc, "Fingerprint:");

    // Create png image
    cairo_surface_write_to_png(surface, "fingerpring.png");

    // Clean and destroy resources
    cairo_destroy(cc);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

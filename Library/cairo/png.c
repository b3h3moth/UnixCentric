#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cairo/cairo.h>

#define SIZE 2048

int main(void) {
    cairo_surface_t *surface;
    cairo_t *cc;
    FILE *fd;
    char public_key[SIZE];
    size_t read;

    fd = fopen("public.key", "r");
    while ((read = fread(public_key, 1, SIZE, fd)) != 0) {
        fwrite(public_key, 1, read, stdout);
    }

    // Create surface (600x800 px) and cairo context
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 600, 800);
    cc = cairo_create(surface);

    // Draw in white
    cairo_set_source_rgb(cc, 255, 255, 255);

    // Set font-type
    cairo_select_font_face(cc, "Sans", CAIRO_FONT_SLANT_NORMAL, \
                                       CAIRO_FONT_WEIGHT_NORMAL);
    // Set font-size
    cairo_set_font_size(cc, 15);

    // Move to 10.0, 10.0 position and drawing text
    cairo_move_to(cc, 1.0, 1.0);
    cairo_show_text(cc, "Hacking on Planet Earth");

    // Create png image
    cairo_surface_write_to_png(surface, "fingerpring.png");

    // Clean and destroy resources
    cairo_destroy(cc);
    cairo_surface_destroy(surface);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>

// Formato A5 con 72 dpi
#define WIDTH       420
#define HEIGHT      595
#define STR_SIZE    200 // Max string size

int main(int argc, char **argv) {
    char input_text[STR_SIZE];
    FILE *fp;
    float position;
    char pdf_file[] = "file.pdf";
    
    cairo_surface_t *surface;
    cairo_t *cr;
    surface = cairo_pdf_surface_create(pdf_file, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_select_font_face (cr, "Monospace", CAIRO_FONT_SLANT_NORMAL, \
                                        CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size (cr, 14.0);
    
    // Posizione iniziale del testo
    position = 50.0;

    if ((fp = fopen("text.txt", "r")) == NULL) {
        fprintf(stderr, "Err: fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
  
    while (fgets(input_text, sizeof(input_text), fp) != NULL) {
        int len = strlen(input_text) - 1;
        
        // Se si giugne alla fine del file, inserire il null-character
        if (input_text[len] == '\n')
            input_text[len] = 0;
        
        //printf("\x0a %s", input_text);
        printf("%s\n", input_text);
        
        cairo_move_to(cr, 8.0, position);
        cairo_show_text(cr, input_text);
        
        position += 8;
    }
    
    fclose(fp);
    cairo_show_page(cr);
    cairo_surface_destroy(surface);
    cairo_destroy(cr);

    return(EXIT_SUCCESS);
}

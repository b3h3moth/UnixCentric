#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>

// Formato A4 con 72 dpi (bassa risoluzione)
#define WIDTH       595
#define HEIGHT      842
#define STR_SIZE    200 // Max string size

int main(int argc, char **argv) {
    float position;
    char str[200];
    FILE *fp;
    char pdf_file[] = "file.pdf";
    
    cairo_surface_t *surface;
    cairo_t *cr;
    surface = cairo_pdf_surface_create(pdf_file, WIDTH, HEIGHT);
    cr = cairo_create(surface);
    

    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_select_font_face (cr, "Sans", CAIRO_FONT_SLANT_NORMAL, \
                                        CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size (cr, 5.0);
    
    // Posizione iniziale del testo
    position = 50.0;

    if ((fp = fopen("text.txt", "r")) == NULL) {
        fprintf(stderr, "Err: fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
  
    while (fgets(str, sizeof(str), fp) != NULL) {
        int len = strlen(str)-1;
        
        if(str[len] == '\n') str[len] = 0;
        printf("\x0a %s", str);
        
        cairo_move_to(cr, 8.0, position);
        cairo_show_text(cr, str);
        
        position+=8;
    }
    
    fclose(fp);
    cairo_show_page(cr);
    cairo_surface_destroy(surface);
    cairo_destroy(cr);

    return(EXIT_SUCCESS);
}

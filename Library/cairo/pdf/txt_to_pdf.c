#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>

// Formato A4 con 72 dpi
#define WIDTH       595
#define HEIGHT      842
#define STR_SIZE    200

/* Il programma riceve in input un file, nel caso specifico 
e' il sorgente '.c' del programma stesso, e lo salva in 
una pagina A4 in formato pdf */

int main(void) {
    char input_text[STR_SIZE];
    FILE *fp;
    float pos_x = 10.0, pos_y = 20.0;
    char pdf_file[] = "txt_to_pdf.pdf";
    int i;
    
    cairo_surface_t *surface;
    cairo_t *cr;
    surface = cairo_pdf_surface_create(pdf_file, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_select_font_face (cr, "Monospace", CAIRO_FONT_SLANT_NORMAL, \
                                        CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size (cr, 9.0);

    if ((fp = fopen("txt_to_pdf.c", "r")) == NULL) {
        fprintf(stderr, "Err: fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
  
    while (fgets(input_text, STR_SIZE, fp) != NULL) {
        int len = strlen(input_text) - 1;

        // Sostituzione di ciascuna new-line con un null-character
        for (i=0; i<len; i++) {
            if (input_text[i] == '\n')
                input_text[i] = '\0';
        }
        
        // Scrittura del testo
        cairo_move_to(cr, pos_x, pos_y);
        cairo_show_text(cr, input_text);

        // Spazio tra le righe
        pos_y += 12;
    }
    
    fclose(fp);
    cairo_show_page(cr);
    cairo_surface_destroy(surface);
    cairo_destroy(cr);

    return(EXIT_SUCCESS);
}

/* E' consigliabile tuttavia non utilizzare le API di Cairo inerenti
il testo, poiche' e' il team di sviluppo stesso ad affermare che 
sono state create come una sorta di giocattolo utile essenzialmente
per le demo, ma non adatte sulle applicazioni finali. 
Si consiglia l'utilizzo della libreria Pango, specifica per il testo,
che peraltro si integra alla perfezione con Cairo. 

Ho potuto notare che con stringhe di lunghezze superiori ai 100 caratteri ci
sono degli enormi problemi di formattazione.*/

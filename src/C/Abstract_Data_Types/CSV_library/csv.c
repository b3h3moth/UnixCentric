#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"

static void reset(void);
static int end_of_line(FILE *fin, int c);
static int split(void);
static char *advquoted(char *p);

// Legge una linea dal file di input e se necessario cresce
char *csv_getline(FILE *fin) {
    int i, c;
    char *newl, *news;

    // Allocazione della memoria alla prima chiamata
    if (line == NULL) { 
        max_line = max_field = 1;
        
        line = malloc(max_line);
        sline = malloc(max_line);
        field = malloc(max_field * sizeof(field[0]));

        // memoria esaurita
        if (line == NULL || sline == NULL || field == NULL) {
            reset();
            return NULL; 
        }
    }

    for (i = 0; (c = fgetc(fin)) != EOF && !end_of_line(fin, c); i++) {
        // La linea aumenta
        if (i >= max_line-1) {
            // raddoppia la dimensione corrente
            max_line *= 2;
            newl = realloc(line, max_line);
            news = realloc(sline, max_line);

            // memoria esaurita
            if (newl == NULL || news == NULL) {
                reset();
                return NULL; 
            }
            line = newl;
            sline = news;
        }
        line[i] = c;
    }
    line[i] = '\0';

    // memoria esaurita
    if (split() == NOMEM) {
        reset();
        return NULL;
    }

    return (c == EOF && i == 0) ? NULL : line;
}

// Imposta nuovamente le variabili al valore di default
static void reset(void) {
    free(line);
    free(sline);
    free(field);
    line = NULL;
    sline = NULL;
    field = NULL;
    max_line = max_field = nfield = 0;
}

// Verifica la presenza di '\r, \n, \r\n, EOF' ed eventualmente li rimuove
static int end_of_line(FILE *fin, int c) {
    int eol;

    eol = (c == '\r' || c == '\n');
    
    if (c == '\r') {
        c = fgetc(fin);
        
        if (c != '\n' && c != EOF)
            // Rimette a posto il carattere pocanzi letto
            ungetc(c, fin);
    }
    
    return eol;
}

// Suddivide la linea 'line' in campi
static int split(void) {
    char *p, **newf;
    // puntatore al carattere di sperazione temporaneo
    char *septr;
    // carattere di sperazione temporaneo
    char sepc;

    nfield = 0;

    if (line[0] == '\0')
        return 0;

    strcpy(sline, line);
    p = sline;

    do {
        if (nfield >= max_field) {
            // raddoppia la dimensione corrente
            max_field *= 2;

            newf = realloc(field, max_field * sizeof(field[0]));

            if (newf == NULL)
                return NOMEM;

            field = newf;
        }
       
        if (*p == '"')
            // salta il carattere 'doppio apice' iniziale
            septr = advquoted(++p);
        else
            septr = p + strcspn(p, field_sep);

        sepc = septr[0];
        septr[0] = '\0';
        // Termina il campo
        field[nfield++] = p;
        p = septr +1;
    } while (sepc == ',');

    return nfield;
}

/* campo tra 'doppi apici', restituisce il puntatore al successivo carattere
di separazione  */
static char *advquoted(char *p) {
    int i, j;

    for (i=j=0; p[j] != '\0'; i++, j++) {
        if (p[j] == '"' && p[++j] != '"') {
            // copia fino al prossimo separatore o fino a \0
            int k = strcspn(p+j, field_sep);
            memmove(p+i, p+j, k);
            i += k;
            j += k;
            break;
        }
        p[i] = p[j];
    }
    p[i] = '\0';

    return p+j;
}

// Restituisce il puntatore all'n-esimo campo
char *csv_field(int n) {
    if (n<0 || n >= nfield)
        return NULL;

    return field[n];
}

// Restituisce il numero di campi
int csv_nfield(void) {
    return nfield;
}

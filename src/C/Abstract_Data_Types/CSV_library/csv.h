#ifndef CSV_H
#define CSV_H

// legge la successiva linea di input
extern char *csv_getline(FILE *f);
// restituisce il campo n
extern char *csv_field(int n);
// restituisce il numero di campi
extern int csv_nfield(void);

// segnale di memoria esaurita
enum { NOMEM = -2 };

// caratteri input
static char *line = NULL;
// copia linea usata per la suddivisione
static char *sline = NULL;

// dimensione di line[] e sline[]
static int max_line = 0;
// puntatori ai campi
static char **field = NULL;
// dimensione di field[]
static int max_field = 0;
// numero di campi in field[]
static int nfield = 0;
// caratteri di separazione tra i campi
static char field_sep[] = ",";

#endif

#include <stdio.h>
#include <stdlib.h>
#include <sqlite.h>

/* Lo scopo del programma e' di creare un database per l'inserimento di 
immagini */

int main(void) {
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    FILE *fp = NULL;
    int flen = 0;
    int size = 0;
    int rc = 0;
    char *err_msg = 0;
    char *sql = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Per i tipi di dato 'blob' si deve lavorare con file binary
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open image: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Sposta il file pointer alla fine del file in lettura, poiche' e' 
    necessario calcolare il peso dell'immagine e si verifica che il risultato
    sia privo di errori. */
    fseek(fp, 0, SEEK_END);
    
    
    return(EXIT_SUCCESS);
}

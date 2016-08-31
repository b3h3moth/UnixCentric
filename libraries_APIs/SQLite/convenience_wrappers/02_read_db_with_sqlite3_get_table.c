#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di leggere i result di una tabella avvalendosi
della funzione sqlite3_get_table(), il nome del database e' fornito come 
argomento. */

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    char    **result = NULL;
    char    *sql_query = NULL;
    char    *err = NULL;
    int     rc = 0;
    int     i, j, nrows, ncols;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Creazione del database
    if (sqlite3_open(argv[1], &db)) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }

    // Comando SQL per la lettura dei dati da una tabella
    sql_query = "SELECT * from song ORDER by id";

    /* Lettura dei record mediante la funzione sqlite3_get_table().
    Usando tale funzione non ci si deve preoccupare di creare una callback().*/
    rc = sqlite3_get_table(db, sql_query, &result, &nrows, &ncols, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. can'texecute sql query: \'%s\'\n", err);
        sqlite3_free(err);
    }

    // Stampa ciascun record, riga per riga
    for (i=0; i<nrows; i++) {
        
        // colonna per colonna
        for (j=0; j<ncols; j++) {
            /* I primi quattro elementi contengono i nomi delle colonne, per
            cui si salta direttamente al contenuto dei record stessi */
            fprintf(stdout, "%2s, ", result[(i+1) * ncols + j]);
        }
        
        fputc('\n', stdout);
    }

    // Rilascio della memoria relativa ai record contenuti in result.
    sqlite3_free_table(result);

    // Close database connection
    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

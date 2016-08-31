#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' l'apertura della connessione al database e la 
relativa creazione dello stesso - per il momento si tratta solo di un file 
vuoto - mediante la funzione specifica, il nome del database stesso e' 
fornito come argomento in input. */

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    int res = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Inizializzazione della libreria
    if (sqlite3_initialize() != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to initialize the library\n");
        exit(EXIT_FAILURE);
    }

    // Creazione della connessione al database
    res = sqlite3_open(argv[1], &db);

    if (res != SQLITE_OK) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    printf("Library \'%s\' successfully initialized..\n", sqlite3_libversion());
    printf("Database \'%s\' successfully created.\n", argv[1]);

    // Close database connection
    if (sqlite3_close(db) == SQLITE_OK)
        puts("Closed database connection");

    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

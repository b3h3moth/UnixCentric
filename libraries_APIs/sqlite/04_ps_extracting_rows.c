#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' l'estrazione dei dati da una tabella mediante la
creazione di una 'Prepared Statement'. Il nome del database e' fornito in
input */

int main(int argc, char *argv[]) {
    sqlite3      *db = NULL;
    sqlite3_stmt *stmt = NULL;
    int          res = 0;
    int          flags = SQLITE_OPEN_READONLY;
    char         *sql_str = "SELECT msg FROM note ORDER by id";

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Inizializzazione della libreria
    if (sqlite3_initialize() != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to initialize the library.\n");
        exit(EXIT_FAILURE);
    }

    /* Creazione della connessione al database */
    res = sqlite3_open_v2(argv[1], &db, flags, NULL);

    if (res != SQLITE_OK) {
        fprintf(stderr, "Err. can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Creazione della "Prepared Statement".
    if (sqlite3_prepare_v2(db, sql_str,-1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to create Prepared Statement.\n");
        exit(EXIT_FAILURE);
    }

    // Estrazione dei dati riga per riga
    while (sqlite3_step(stmt) == SQLITE_ROW)
        printf("%s\n", sqlite3_column_text(stmt, 0));

    // Rilascio delle risorse relative alla Prepared Statement
    if (sqlite3_finalize(stmt) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to finalize.\n");
        exit(EXIT_FAILURE);
    }

    // Close database connection
    if (sqlite3_close_v2(db) != SQLITE_OK)
        fprintf(stderr, "Err. Unable to close connection.\n");
        exit(EXIT_FAILURE);
    }

    // Rilascio delle risorse dell'inizializzazione
    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

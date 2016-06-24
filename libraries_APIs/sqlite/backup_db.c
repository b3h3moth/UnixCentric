#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Lo scopo del programma e di creare un backup del dabatase

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    int res = 0;
    // Campo di bit che indica la creazione del database in lettura/scrittura
    int flags = SQLITE_OPEN_READWRITE;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Inizializzazione della libreria
    if (sqlite3_initialize() != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to initialize the library.\n");
        exit(EXIT_FAILURE);
    }

    // Creazione della connessione al database
    res = sqlite3_open_v2(argv[1], &db, flags, NULL);

    if (res != SQLITE_OK) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Close database connection
    if (sqlite3_close_v2(db) == SQLITE_OK)
        puts("Closed database connection");

    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

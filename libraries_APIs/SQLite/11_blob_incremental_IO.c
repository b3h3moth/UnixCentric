#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' la manipolazioni del tipo di dato BLOB mediante
I/O incrementale */

int main(int argc, char *argv[]) {
    sqlite3      *db = NULL;
    sqlite3_stmt *stmt = NULL;
    int          res = 0;
    int          flags = SQLITE_OPEN_READWRITE;
    char         *sql_rowid = "SELECT rowid FROM ? WHERE file_name like ?";
    char         *sql_data = "SELECT data from ? WHERE file_name like ?";


    if (argc != 4) {
        fprintf(stderr, "Usage: %s <database> <table> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Nome della tabella e del dato binario di prelevare
    const char *const table_name = (argc && argv[2]) ? argv[2] : "";
    const char *const data_name = (argc && argv[3]) ? argv[3] : "";

    // Inizializzazione della libreria
    if (sqlite3_initialize() != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to initialize the library.\n");
        exit(EXIT_FAILURE);
    }

    /* Creazione della connessione al database */
    res = sqlite3_open_v2(argv[1], &db, flags, NULL);

    if (res != SQLITE_OK) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Creazione della "Prepared Statement".
    if (sqlite3_prepare_v2(db, sql_rowid,-1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to create Prepared Statement.\n");
        exit(EXIT_FAILURE);
    }



    // L'esecuzione del codice VDBE
    if (sqlite3_step(stmt) == SQLITE_DONE)
        printf("... Statement successfully executed: %s\n", sql_rowid);

    // Rilascio della prepared statement
    if (sqlite3_finalize(stmt) == SQLITE_OK)
        puts("... Prepared Statemend destroyed.");

    // Close database connection
    if (sqlite3_close_v2(db) == SQLITE_OK)
        puts("... Closed database connection. ");

    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

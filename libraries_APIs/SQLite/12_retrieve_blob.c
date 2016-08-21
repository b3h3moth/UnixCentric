#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di recuperare un dato binario di tipo BLOB dalla
colonna e salvarlo in nuovo file. Il nome del database e del file binario da 
salvare sono forniti in input. */

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    FILE *fblob = NULL;
    int res = 0;
    int blob_size = 0;
    int flags = SQLITE_OPEN_READWRITE;
    char *blob_data = NULL;
    char *sql_data = "SELECT data FROM blobs WHERE id = 1";

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <database> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Nome della tabella e del dato binario di prelevare
    const char *const db_name = (argc && argv[1]) ? argv[1] : "";
    const char *const data_name = (argc && argv[2]) ? argv[2] : "";

    // Inizializzazione della libreria
    if (sqlite3_initialize() != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to initialize the library.\n");
        exit(EXIT_FAILURE);
    }

    /* Creazione della connessione al database */
    res = sqlite3_open_v2(db_name, &db, flags, NULL);

    if (res != SQLITE_OK) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Creazione della "Prepared Statement".
    if (sqlite3_prepare_v2(db, sql_data,-1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to create Prepared Statement.\n");
        exit(EXIT_FAILURE);
    }

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        blob_size = sqlite3_column_bytes(stmt, 0);
        blob_data = malloc(blob_size);
        memcpy(blob_data, sqlite3_column_blob(stmt, 0), blob_size);
    }

    fblob=fopen(data_name, "w");
    fwrite(blob_data, blob_size, 1, fblob);
    fclose(fblob);

    // Rilascio della prepared statement
    if (sqlite3_finalize(stmt) == SQLITE_OK)
        puts("... Prepared Statemend destroyed.");

    // Close database connection
    if (sqlite3_close_v2(db) == SQLITE_OK)
        puts("... Closed database connection. ");

    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

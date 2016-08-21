#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' la manipolazioni del tipo di dato BLOB mediante
I/O incrementale */

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    sqlite3_blob *blob = NULL;
    FILE *fblob = NULL;
    int res = 0;
    int blob_size = 0;
    int flags = SQLITE_OPEN_READWRITE;
    sqlite3_int64 rowid = 0;
    char *blob_data = NULL;
    char *err_msg = 0;
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

    sqlite3_blob_open(db, "main", "blobs", "data", 1, 0, &blob);

    blob_size = sqlite3_blob_bytes(blob);
    blob_data = malloc(blob_size);
    sqlite3_blob_read(blob, blob_data, blob_size, 0);
    sqlite3_blob_close(blob);

    fblob=fopen(data_name, "w");
    fwrite(blob_data, blob_size, 1, fblob);
    fclose(fblob);
    
    if (sqlite3_step(stmt) == SQLITE_DONE)
        printf("... Statement successfully executed: %s\n", sql_data);

    // Rilascio della prepared statement
    if (sqlite3_finalize(stmt) == SQLITE_OK)
        puts("... Prepared Statemend destroyed.");

    // Close database connection
    if (sqlite3_close_v2(db) == SQLITE_OK)
        puts("... Closed database connection. ");

    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di inserire alcune righe del database mediante
la creazione di una "Prepared Statement". */

int main(int argc, char *argv[]) {
    sqlite3      *db = NULL;
    sqlite3_stmt *stmt = NULL;
    int          res = 0;
    int          flags = SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE;
    char         *sql_str = 
        "INSERT INTO addressbook(fullname, alias, email)"
        "VALUES ('rossella', 'ros', 'ros@free.org');"
        "INSERT INTO addressbook(fullname, alias, email)"
        "VALUES ('francesco', 'frank', 'franky@slash.org');"
        "INSERT INTO addressbook(fullname, alias, email)"
        "VALUES ('luca', 'lu', 'liuc@step.org');"
        "INSERT INTO addressbook(fullname, alias, email)"
        "VALUES ('carlotta', 'carl', 'carl@otta.org');";

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
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    if (sqlite3_prepare_v2(db, sql_str,-1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to create Prepared Statement.\n");
        exit(EXIT_FAILURE);
    }

    if (sqlite3_step(stmt) == SQLITE_DONE)
        printf("... Statement successfully executed: %s\n", sql_str);

    if (sqlite3_finalize(stmt) == SQLITE_OK)
        puts("... Prepared Statemend destroyed.");

    // Close database connection
    if (sqlite3_close_v2(db) == SQLITE_OK)
        puts("... Closed database connection. ");

    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

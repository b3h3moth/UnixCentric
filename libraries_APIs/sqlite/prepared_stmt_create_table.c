#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' la creazione di una tabella all'interno del 
database fornito come argomento. Non si deve utilizzare il wrapper ma le
prepared statements. */

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    // SQL statement il cui compito e' la creazione di una tabella 
    char *sql_str = "CREATE TABLE note(\
           id INTEGER PRIMARY KEY,\
           data DATE NOT NULL,\
           time TIME NOT NULL,\
           msg TEXT NOT NULL)";

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database_name.db>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Creazione del database
    if (sqlite3_open(argv[1], &db)) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }
    sqlite3_prepare_v2(db, sql_str, -1, &stmt, NULL);
    // Poiche' si crea una tabella serve una sola funzione "stepped"
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    // Close database connection
    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

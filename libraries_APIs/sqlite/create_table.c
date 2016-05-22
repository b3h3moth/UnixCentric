#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' la creazione di una tabella all'interno del 
database fornito come argomento */

int main(int argc, char *argv[]) {
    sqlite3 *db;
    char *sql_query, *err;
    int rc;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database_name.db>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Creazione del database
    if (sqlite3_open(argv[1], &db)) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }

    // Query il cui compito e' la creazione di una tabella suddivisa in campi
    sql_query = "CREATE TABLE note(\
           id INTEGER PRIMARY KEY AUTOINCREMENT,\
           data DATE NOT NULL,\
           time TIME NOT NULL,\
           msg TEXT NOT NULL)";
    
    // Esecuzione della query 'sql'.
    rc = sqlite3_exec(db, sql_query, NULL, NULL, &err);
    if (rc != SQLITE_OK)
        if (err != NULL) {
            fprintf(stderr, "Err. can'texecute sql query: \'%s\'\n", err);
            exit(EXIT_FAILURE);
        }

    printf("Table successfully created within the database: %s\n", argv[1]);

    // Close database connection
    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

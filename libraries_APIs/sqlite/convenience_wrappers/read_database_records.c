#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di leggere i record di una tabella, il nome del
database e' fornito come argomento */

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

    // Comando SQL per la lettura dei dati da una tabella
    sql_query = "SELECT * from note ORDER by id";

    // Lettura dei record mediante la funzione sqlite3_get_table()
    rc = sqlite3_get_table(db, sql_query, NULL, NULL, &err);
    if (rc != SQLITE_OK) {
        if (err != NULL) {
            fprintf(stderr, "Err. can'texecute sql query: \'%s\'\n", err);
            sqlite3_close(db);
            exit(EXIT_FAILURE);
        }
    }

    // Close database connection
    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

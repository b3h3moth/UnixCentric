#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' l'esecuzione di una query per l'inserimento di 
dati all'interno dei vari campi di una tabella */

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

    // Query il cui compito e' il riempimento dei campi
    sql_query = "INSERT INTO note(data, time, msg) VALUES \
           ( date('now'), \
           time('now'), \
           'SQLite C API' )";
    
    // Esecuzione della query 'sql'.
    rc = sqlite3_exec(db, sql_query, NULL, NULL, &err);
    if (rc != SQLITE_OK)
        if (err != NULL) {
            fprintf(stderr, "Err. can'texecute sql query: \'%s\'\n", err);
            exit(EXIT_FAILURE);
        }

    puts("Statements stored in a table");

    // Close database connection
    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

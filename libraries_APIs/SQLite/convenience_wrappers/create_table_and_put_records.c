#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' la creazione di una tabella all'interno del 
database fornito come argomento */

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    char    *sql_create = NULL;
    char    *sql_insert = NULL;
    char    *err = NULL;
    int     rc = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Creazione del database
    if (sqlite3_open(argv[1], &db)) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }

    // Query il cui compito e' la creazione di una tabella suddivisa in campi
    sql_create = "CREATE TABLE IF NOT EXISTS note(  \
                  id INTEGER PRIMARY KEY,           \
                  data DATE NOT NULL,               \
                  time TIME NOT NULL,               \
                  msg TEXT NOT NULL)";
    
    // Esecuzione della query 'sql'.
    rc = sqlite3_exec(db, sql_create, NULL, NULL, &err);
    if (rc != SQLITE_OK) {
        if (err != NULL) {
            fprintf(stderr, "Err. Failed to execute SQL query: \'%s\'\n", err);
        }
        return 1;
    }

    printf("Table successfully created within the database: %s\n", argv[1]);

    // Inserimento di alcuni record nella tabella
    sql_insert = "INSERT INTO note(data, time, msg) VALUES (    \
                  date('now'),                                  \
                  time('now'),                                  \
                  'Take a walk on the wild side')";

    // Esecuzione della query 'sql'.
    rc = sqlite3_exec(db, sql_insert, NULL, NULL, &err);
    if (rc != SQLITE_OK) {
        if (err != NULL) {
            fprintf(stderr, "Err. Failed to execute SQL query: \'%s\'\n", err);
        }
        return 1;
    }

    puts("Record successfully created.");

    // Close database connection
    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

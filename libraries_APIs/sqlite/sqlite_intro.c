#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sqlite3.h>

int main(int argc, char *argv[]) {
    sqlite3     *db;
    char        *err;
    int         rc;
    char        *sql;

    // Creazione del database
    if (sqlite3_open("note.db", &db)) {
        fprintf(stderr, "Err. Open database - %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }

    sql = "CREATE TABLE test4(\
        id INTEGER PRIMARY KEY AUTOINCREMENT,\
        data DATE NOT NULL,\
        ora TIME NOT NULL,\
        testo TEXT NOT NULL)";

    rc = sqlite3_exec(db, sql, NULL, NULL, &err);

    if (rc != SQLITE_OK) {
        if (err != NULL) {
            fprintf(stderr, "Err. SQL - %s\n", err);
            exit(EXIT_FAILURE);
        }
    }

    sql = "INSERT INTO test4(data, ora, testo) \
           VALUES(date('now'), \
           time('now'), \
           'primo messaggio')";

    rc = sqlite3_exec(db, sql, NULL, NULL, &err);

    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

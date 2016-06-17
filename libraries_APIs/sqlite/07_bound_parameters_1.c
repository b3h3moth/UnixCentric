#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di associare, mediante le funzioni della
famiglia sqlite3_bind_*(), alcuni parametri ad altre variabili statiche, e 
infine incapsularli nella stringa SQL da passare al database. */

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    int flags = SQLITE_OPEN_READWRITE;
    int rc = 0;
    int idx = -1;
    char *str_fullname = "bar";
    char *str_alias = "baz";
    char *str_email = "baz@bar.org";
    char *sql_str = "INSERT INTO addressbook (fullname, alias, email)"
                    "VALUES(?, ?, ?)";

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Library initialization
    sqlite3_initialize() {
        fprintf(stderr, "Err. Unable to initialize the library.\n");
        exit(EXIT_FAILURE);
    }

    // Open database connection
    rc = sqlite3_open_v2(argv[1], &db, flags, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Prepare the statement
    sqlite3_prepare_v2(db, sql_str,-1, &stmt, NULL) {
        fprintf(stderr, "Err. Unable to prepare the statement.\n");
        exit(EXIT_FAILURE);
    }

    // Bind the values
    sqlite3_bind_text(stmt, 1, str_fullname, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, str_alias, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, str_email, -1, SQLITE_STATIC);

    // Do the statement
    sqlite3_step(stmt) 

    // Release prepared statement resources
    sqlite3_finalize(stmt);
    // Close database connection
    sqlite3_close_v2(db);
    // Shutdown library initialization
    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di seguire una query dinamica facendo uso della
funzione asprintf().

Note: Whene compiling add -D_GNU_SOURCE 
<clang, gcc> -std=c11 -lsqlite3 -Wall -pedantic -D_GNU_SOURCE file.c
*/

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    int flags = SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE;
    int rc = 0;
    char *sql_query = NULL;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <DBname><name><alias><email>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Library initialization
    sqlite3_initialize();

    // Open database connection
    rc = sqlite3_open_v2(argv[1], &db, flags, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Allocate the right memory to hold the SQL query
    asprintf(&sql_query, "INSERT INTO addressbook (fullname, alias, email) \
            VALUES ('%s', '%s', '%s')", argv[2], argv[3], argv[4]);

    // Prepare the statement
    rc = sqlite3_prepare_v2(db, sql_query,-1, &stmt, NULL);

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Err. Stepping through the statement.\n");
    }

    // Release prepared statement resources
    sqlite3_finalize(stmt);
    // Close database connection
    sqlite3_close_v2(db);
    // Shutdown library initialization
    sqlite3_shutdown();
    // Free pointer memory
    free(sql_query);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    int flags = SQLITE_OPEN_READWRITE;
    int rc = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database name>\n", argv[0]);
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


    // Close database connection
    sqlite3_close_v2(db);
    // Shutdown library initialization
    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

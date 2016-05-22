#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' la creazione del database mediante la API 
specifica, il nome del database stesso e' fornito in input. */

int main(int argc, char *argv[]) {
    sqlite3 *db;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Creazione del database
    if (sqlite3_open(argv[1], &db)) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }

    printf("Database \'%s\' successfully created.\n", argv[1]);

    // Close database connection
    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

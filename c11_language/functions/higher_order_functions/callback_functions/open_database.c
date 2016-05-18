#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char *argv[]) {
    sqlite3 *db;
    int rc;
    char *err_msg = NULL;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <db> <SQL statement>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Apertura del database fornito come argomento
    rc = sqlite3_open(argv[1], &db);


    return(EXIT_SUCCESS);
}

/* How to compile the program wih sqlite3 header:
$   gcc -std=c11 -Wall -pedantic -lsqlite3 open_database.c -o opendb
$ clang -std=c11 -Wall -pedantic -lsqlite3 open_database.c -o opendb
*/

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Function Prototype
int callback(void *data, int num_col, char **col_data, char **col_name);

/* Lo scopo del programma e' di leggere i record di una tabella mediante la
funzione di callback, il nome del database e' fornito come argomento. */

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    char    *sql_query = NULL;
    char    *err = NULL;
    int     rc = 0;


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
    rc = sqlite3_exec(db, sql_query, callback, NULL, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. can'texecute sql query: \'%s\'\n", err);
        sqlite3_free(err);
    }

    // Close database connection
    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

int callback(void *data, int num_col, char **col_data, char **col_name) {
    int i;

    for (i=0; i<num_col; i++)
        printf("%s: %s\n", col_name[i], col_data[i] ? col_data[i] : "NULL");
    
    return 0;
}

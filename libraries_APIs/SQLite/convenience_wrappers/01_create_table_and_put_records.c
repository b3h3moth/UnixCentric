#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' la creazione di una tabella e l'inserimento di
alcuni record nella tabella stessa, utilizzando allo scopo il 
'convenience wrapper'. Il database e' fornito come primo argomento. */

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
    sql_create = "CREATE TABLE IF NOT EXISTS song(  \
                  id INTEGER PRIMARY KEY,           \
                  data DATE NOT NULL,               \
                  time TIME NOT NULL,               \
                  msg TEXT NOT NULL)";
    
    /* La funzione sqlite3_exec() esegue tutto il processo - preparation,
    execution, finalization - di una 'prepared statement' con una sola 
    chiamata. I record vengono estrapolati dal database mediante la chiamata a
    una funzione di callback, che sara' invocata una volta per ogni riga. */
    rc = sqlite3_exec(db, sql_create, NULL, NULL, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Failed to execute SQL query: \'%s\'\n", err);
        sqlite3_free(err);
    }

    /* Nota: Il messaggio di errore 'err', qualora dovesse essere utilizzato,
             dovra' essere esplicitamente deallocato mediante la funzione 
             sqlite3_free(messaggio_errore). */

    printf("Table successfully created: %s\n", argv[1]);

    // Inserimento di alcuni record nella tabella
    sql_insert = "INSERT INTO song(data, time, msg) VALUES"
                 "(date('now'), time('now'), 'Take a walk on the wild side'),"
                 "(date('now'), time('now'), 'Get up Stand up'),"
                 "(date('now'), time('now'), 'Jamming'),"
                 "(date('now'), time('now'), 'Buffalo Soldier'),"
                 "(date('now'), time('now'), 'Rastaman Vibration')";

    // Esecuzione della query 'sql'.
    rc = sqlite3_exec(db, sql_insert, NULL, NULL, &err);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Failed to execute SQL query: \'%s\'\n", err);
        sqlite3_free(err);
    }

    /* Si utilizza la funzione sqlite3_changes() per ottenere le ultime righe
    modificate */
    printf(" Rows Successfully created: %d\n", sqlite3_changes(db));

    // Close database connection
    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

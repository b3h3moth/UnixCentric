#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' l'estrazione di ciascun record mediante SQL
query multiple, mediante la creazione di una 'Prepared Statement'. 
Il nome del database e' fornito in input. */

int main(int argc, char *argv[]) {
    sqlite3         *db = NULL;
    sqlite3_stmt    *stmt = NULL;
    int             res = 0;
    int             flags = SQLITE_OPEN_READONLY;
    const char      *colnms[4] = {NULL};     // Nomi delle colonne
    char            *tail = NULL;
    char            *sql_str = 
        "SELECT * FROM addressbook ORDER by id;"
        "SELECT * FROM addressbook ORDER by fullname;"
        "SELECT * FROM addressbook ORDER by alias;"
        "SELECT * FROM addressbook ORDER by email;";

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Inizializzazione della libreria
    if (sqlite3_initialize() != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to initialize the library.\n");
        exit(EXIT_FAILURE);
    }

    /* Creazione della connessione al database */
    res = sqlite3_open_v2(argv[1], &db, flags, NULL);

    if (res != SQLITE_OK) {
        fprintf(stderr, "Err. can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    /* Si utilizza la funzione sqlite3_complete() per la verifica della query,
    si basa essenzialmente sul riconoscimento del punto e virgola - semicolon -
    finale */
    while(sqlite3_complete(sql_str)) {
        if (sqlite3_prepare_v2(db, sql_str,-1, &stmt, &tail) != SQLITE_OK) {
            fprintf(stderr, "Err. Unable to create Prepared Statement.\n");
            exit(EXIT_FAILURE);
        }

        // Stampa il nome di ciascuna colonna.
        for (int i=0; i<sqlite3_column_count(stmt); i++)
            colnms[i] = sqlite3_column_name(stmt, i);
    
            printf("%2s %10s %8s %14s\n", \
                    colnms[0], colnms[1], colnms[2], colnms[3]);

        // Estrazione dei dati riga per riga
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            printf("%2d %10s %5s %20s (byte: %3d)\n",                \
                    sqlite3_column_int(stmt, 0),                    \
                    (const char*)sqlite3_column_text(stmt, 1),      \
                    (const char*)sqlite3_column_text(stmt, 2),      \
                    (const char*)sqlite3_column_text(stmt, 3),      \
                    sqlite3_column_bytes(stmt, 3));
        }
        puts("\n");
        
        // L'istruzione successiva da eseguire e' conservata in 'tail'
        sql_str = tail;
    }


    // Rilascio delle risorse relative alla Prepared Statement
    if (sqlite3_finalize(stmt) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to finalize.\n");
        exit(EXIT_FAILURE);
    }

    // Close database connection
    if (sqlite3_close_v2(db) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to close connection.\n");
        exit(EXIT_FAILURE);
    }

    // Rilascio delle risorse di inizializzazione
    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

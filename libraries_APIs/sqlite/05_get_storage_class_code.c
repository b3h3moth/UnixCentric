#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di individuare il tipo di dato all'interno dei
record di un database, mediante la classe di memorizzazione (Storage Class). */

int main(void) {
    sqlite3         *db = NULL;
    sqlite3_stmt    *stmt = NULL;
    int             res = 0;
    int             rc = 0;
    char            *sql_str = "SELECT * FROM note order by time";
    int             flags = SQLITE_OPEN_READONLY;

    // Inizializzazione della libreria
    if (sqlite3_initialize() != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to initialize the library.\n");
        exit(EXIT_FAILURE);
    }

    // Creazione della connessione al database
    res = sqlite3_open_v2("1.db", &db, flags, NULL);

    if (res != SQLITE_OK) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Creazione della "Prepared Statement".
    if (sqlite3_prepare_v2(db, sql_str,-1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to create Prepared Statement.\n");
        exit(EXIT_FAILURE);
    }

    // Il byte-code con l'SQL viene dato in pasto al VDBE
    rc = sqlite3_step(stmt);
    
    /* Warning: E' molto importante collocare la funzione sqlite3_step() subito
    dopo la funzione di 'preparazione', altrimenti si potrebbero avere 
    risultati inattesi.
    Provare ad esempio a collocarla dopo il 'for loop' e verificare il 
    risultato. Si notera' che gli interi della Storage Class saranno inesatti. 
    */

    /* Stampa del nome della colonna, della Storage Classe e del tipo
    dichiarato nella SQL */
    for (int i=0; i<sqlite3_column_count(stmt); i++) {
        printf("Column: %4s | Storage Class: %i | Declared As: %s\n", \
               sqlite3_column_name(stmt, i), sqlite3_column_type(stmt, i), \
               sqlite3_column_decltype(stmt, i));
    }


    // Rilascio delle risorse applicate alla 'Prepared Statement'
    if (sqlite3_finalize(stmt) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to finalize.\n");
        exit(EXIT_FAILURE);
    }

    // Close database connection
    if (sqlite3_close_v2(db) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to close connection.\n");
        exit(EXIT_FAILURE);
    }

    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

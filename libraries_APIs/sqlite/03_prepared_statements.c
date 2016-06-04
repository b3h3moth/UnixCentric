#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' la creazione di un database ex-novo, il nome del
database sara' fornito in input, dopodiche' mediante una query sara' creata una
tabella mediante le "Prepared Statements". */

int main(int argc, char *argv[]) {
    sqlite3      *db = NULL;
    sqlite3_stmt *stmt = NULL;
    int          res = 0;
    int          flags = SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE;
    char         *sql_str = "CREATE TABLE note(id INTEGER PRIMARY KEY,"
                           "data DATE NOT NULL,"
                           "time TIME NOT NULL,"
                           "msg TEXT NOT NULL);";

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
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    /* Creazione della "Prepared Statement".
    Una "Prepared Statement" e' l'istanza di una singola dichiarazione SQL,
    compilata in forma binaria e pronta per essere valutata; il processo di
    preparazione pertanto e' la conversione di un comando SQL in una
    "Prepared Statement" in forma binaria (compiled object code o byte-code).
    
    Una dichiarazione e' eseguita (stepped through) riga per riga fin quando 
    non ci sono piu' righe da valutare.
    
    Le Prepared Statements - a differenza delle connessioni al database che 
    possono essere aperte, utilizzate per un periodo di tempo e poi chiuse - 
    possono trovarsi in diversi stati, come ad esempio essere eseguite,
    essere resettate, essere eseguite piu' volte, non eseguite.

    La conversione di un comando SQL da stringa a "Prepared Statement" avviene
    per mezzo una delle funzioni della famiglia sqlite3_prepare_*(), nello
    specifico la v2.
    */
    if (sqlite3_prepare_v2(db, sql_str,-1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to create Prepared Statement.\n");
        exit(EXIT_FAILURE);
    }

    /* La dichiarazione SQL ora e' in forma di byte-code, esso e' dato in pasto
    al VDBE (Virtual DataBase Engine) che si occupera' di processarlo.
    L'esecuzione del codice VDBE e' responsabilita' della funzione
    sqlite3_step(). */

    sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    // Close database connection
    if (sqlite3_close_v2(db) == SQLITE_OK)
        puts("Closed database connection");

    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

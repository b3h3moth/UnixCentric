#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' l'apertura di una connessione al database e la
conseguente creazione del database stesso - che peraltro nel caso specifico
sara' semplicemente un file vuoto -, mediante la nuova versione della funzione
denominata con prefisso 'v2'. Il nome del database e' fornito come argomento 
dalla command line.

La documentazione SQLite consiglia espressamente l'utilizzo della nuova 
versione sqlite3_open_v2(), che conferisce maggior controllo sull'apertura e il
processamente del database.

Il primo argomento puo' essere:
- un filename;
- una stringa ':memory:', caso in cui sara' creato un database in RAM per la 
  sola durata del programma in esecuzione, ovvero della sessione;
- una stringa vuota o null, nel qual caso sara' creato un file temporaneo nel
  filesystem che sara' eliminato alla chiusura della connessione.
*/

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    int res = 0;
    // Campo di bit che indica la creazione del database in lettura/scrittura
    int flags = SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Inizializzazione della libreria
    if (sqlite3_initialize() != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to initialize the library.\n");
        exit(EXIT_FAILURE);
    }

    /* Creazione della connessione al database, la versione v2 della libreria
    supporta quattro parametri */
    res = sqlite3_open_v2(argv[1], &db, flags, NULL);

    if (res != SQLITE_OK) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    printf("Library \'%s\' successfully initialized..\n", sqlite3_libversion());
    printf("Database \'%s\' successfully created.\n", argv[1]);

    // Close database connection
    if (sqlite3_close_v2(db) == SQLITE_OK)
        puts("Closed database connection");

    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

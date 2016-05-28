#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' la creazione del database - per il momento si
tratta solo di un file vuoto - mediante la funzione specifica, il nome del 
database stesso e' fornito come argomento in input.

Si utilizza la nuova funzione con suffisso _v2.

E' consigliabile utilizzare nei nuovi programmi la versione con suffisso _v2,
che conferisce maggior controllo sull'apertura e il processamente del database. 
*/

int main(int argc, char *argv[]) {
    sqlite3 *db;

    // Campo di bit che indica la creazione del database in lettura/scrittura
    int flags = SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <database name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Creazione del database, la nuova versione della funzione supporta 
    quattro  parametri */
    if (sqlite3_open_v2(argv[1], &db, flags, NULL )) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }

    printf("Database \'%s\' successfully created.\n", argv[1]);

    // Close database connection
    sqlite3_close_v2(db);

    return(EXIT_SUCCESS);
}

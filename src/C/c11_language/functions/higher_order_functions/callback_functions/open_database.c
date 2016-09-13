#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *null, int argc, char **argv, char **col_name) {
    int i;

    for (i=0; i<argc; i++)
        printf("%s = %s\n", col_name[i], argv[i] ? argv[i] : "NULL");

    puts(" ");
    return 0;
}

/* Lo scopo del programma e' di implementare una funzione di callback() a
supporto della chiamata sqlite3_exec(), naturalmente i benefici di tale 
chiamata saranno evidenti qualora il database contenga effettivamente dei dati.

Il convenience wrapper di SQLite ne e' un esempio evidente.
*/

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

    if (rc) {
        fprintf(stderr, "Err: Can't open DB %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Invio di una query SQL al database, ricevuta come argomento
    rc = sqlite3_exec(db, argv[2], callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err: Can't execute SQL statement %s\n", err_msg);
        sqlite3_free(err_msg);
        exit(EXIT_FAILURE);
    }

    // Chiusura connessione al database
    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

/* 
A supporto e' sato inserito un file .sql con alcune query dedicate sia alla
creazione della tabella sia all'inserimento di dati nei campi previsti dalla 
tabella stessa.

Prima di compilare, upload dei dati all'interno del db:
$ cat data.sql | sqlite3 my.db

Fase di compilazione del sorgente:
$   gcc -std=c11 -Wall -pedantic -lsqlite3 open_database.c -o opendb
$ clang -std=c11 -Wall -pedantic -lsqlite3 open_database.c -o opendb

Esecuzione del programma:
$ ./opendb my.db "SELECT * FROM oslist;"

[...]

*/

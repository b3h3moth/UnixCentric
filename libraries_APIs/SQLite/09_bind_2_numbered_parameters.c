#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di associare, mediante le funzioni della
famiglia 'sqlite3_bind_*()', alcuni parametri a dei valori e incapsularli nella 
stringa SQL da passare al database, tali valori sono forniti in input. 
Infine, stampa a video diverse peculiarita' dei 'bound parameters'. 

Nel caso specifico si utilizzeranno 'numbered parameters', contrassegnati
mediante '?<index>', dove 'index e' un intero. */

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    int flags = SQLITE_OPEN_READWRITE;
    int rc = 0;
    /* Stringa SQL con 'numbered parameters'.
    Il numero del parametro e' definito dal programmatore. La sintassi come e'
    evidente richiede il punto interrogativo seguito dal numero del parametro.
    Il range di numeri utilizzabile varia da 1 a 999, tuttavia e' consigliabile
    adoperare numeri bassi. */
    char *sql_str = "INSERT INTO addressbook (fullname, alias, email)"
                    "VALUES(?10, ?20, ?30)";

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <DB>,<name>,<alias>,<email>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Le stringhe ricevute in input diventano costanti */
    const char *const str_fullname = (argc && argv[2]) ? argv[2] : "";
    const char *const str_alias = (argc && argv[3]) ? argv[3] : "";
    const char *const str_email = (argc && argv[4]) ? argv[4] : "";

    // Library initialization
    if (sqlite3_initialize() != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to initialize the library.\n");
        exit(EXIT_FAILURE);
    }

    // Open database connection
    rc = sqlite3_open_v2(argv[1], &db, flags, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. can't create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Prepare the statement
    rc = sqlite3_prepare_v2(db, sql_str, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Can't prepare the statement.\n");
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Bind del primo parametro, l'indice associato vale 10
    rc = sqlite3_bind_text(stmt, 10, str_fullname, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Binding the value (%i).\n", rc);
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Bind del secondo parametro, l'indice associato vale 20
    rc = sqlite3_bind_text(stmt, 20, str_alias, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Binding the value (%i).\n", rc);
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Bind del terzo parametro, l'indice associato vale 30
    rc = sqlite3_bind_text(stmt, 30, str_email, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Binding the value (%i).\n", rc);
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_DONE) {
        puts("... SQL Statement Successfully Executed.");
    }

    // Release prepared statement resources
    sqlite3_finalize(stmt);
    // Close database connection
    sqlite3_close_v2(db);
    // Shutdown library initialization
    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

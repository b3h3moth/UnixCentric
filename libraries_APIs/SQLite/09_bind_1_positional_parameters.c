#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di associare, mediante le funzioni della
famiglia 'sqlite3_bind_xxx()', alcuni parametri a dei valori e incapsularli 
nella stringa SQL da passare al database, tali valori sono forniti in input.
Infine, stampa a video diverse peculiarita' dei 'bound parameters'.

Nel caso specifico si utilizzeranno parametri posizionali - positional 
parameters - contrassegnati mediante '?' . 
*/

int main(int argc, char *argv[]) {
    /* I 'bound parameters' sono dei token inseriti all'interno di una stringa
    SQL, agiscono come una sorta di segnaposto per qualsiasi valore letterale e
    possono essere numeri oppure stringhe a singola quotatura, devono essere 
    collocati nella stringa SQL prima della preparazione della dichiarazione.
    
    Successivamente, dopo che la dichiarazione e' stata preparata, ma prima 
    dell'esecuzione, e' possibile associare/legare (bind) un valore al 
    rispettivo parametro. Alla fine dell'esecuzione della dichiarazione e' 
    possibile resettare la dichiarazione stessa e ripetere il ciclo di binding
    con nuovi parametri.

    Nota: Ogni parametro all'interno della dichiarazione e' referenziato 
          mediante un indice che parte da uno.

    SQLite supporta cinque templates a cui associare parametri:
    1 - ?       , parametro posizionale o anonimo con indice automatico. 
                  L'indice e' unico, sequenziale e inizia da 1;
    2 - ?<index>, parametro con indice numerico esplicito;
    3 - :<name> , parametro denominato con indice automatico;
    4 - @<name> , parametro denominato con indice automatico;
    5 - $<name> , parametro denominato con indice automatico.
    */
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    int flags = SQLITE_OPEN_READWRITE;
    int rc = 0;
    // Stringa SQL con i parametri posizionali.
    char *sql_str = "INSERT INTO addressbook (fullname, alias, email)"
                    "VALUES(?, ?, ?)";

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
    rc = sqlite3_prepare_v2(db, sql_str,-1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Can't prepare the statement.\n");
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Bind the first value
    rc = sqlite3_bind_text(stmt, 1, str_fullname, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Binding the value (%i).\n", rc);
        return 1;
    }

    // Bind the second value
    rc = sqlite3_bind_text(stmt, 2, str_alias, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Binding the value (%i).\n", rc);
        return 1;
    }

    // Bind the third value
    rc = sqlite3_bind_text(stmt, 3, str_email, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Binding the value (%i).\n", rc);
        return 1;
    }

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_DONE) {
        puts("... SQL Statement Successfully Executed.");
        // Stampa il numero totale dei parametri
        printf("Total bound parameters: %d\n", \
                sqlite3_bind_parameter_count(stmt));
    }

    // Release prepared statement resources
    sqlite3_finalize(stmt);

    // Close database connection
    sqlite3_close_v2(db);
    // Shutdown library initialization
    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

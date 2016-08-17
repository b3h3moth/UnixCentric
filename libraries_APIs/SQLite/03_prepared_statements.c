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
    char         *sql_str = "CREATE TABLE addressBook(id INTEGER PRIMARY KEY,"
                           "fullname TEXT NOT NULL UNIQUE,"
                           "alias TEXT NOT NULL,"
                           "email TEXT NOT NULL UNIQUE);";

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
    possono trovarsi in diversi stati e in ciascun stato posso essere invocate
    o meno delle funzioni. Gli stati sono: "ready", "running", e "done.

    La conversione di un comando SQL da stringa a "Prepared Statement" avviene
    per mezzo della funzione sqlite3_prepare_v2().
    */
    if (sqlite3_prepare_v2(db, sql_str,-1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Err. Unable to create Prepared Statement.\n");
        exit(EXIT_FAILURE);
    }

    /* La dichiarazione SQL ora e' in forma di byte-code, il quale viene dato 
    in pasto al VDBE (Virtual DataBase Engine) che si occupera' di processarlo.

    L'esecuzione del codice VDBE e' responsabilita' della funzione
    sqlite3_step(), che ritorna una riga per volta, per cui se si volesse
    avanzare riga per riga si dovrebbe invocare la funzione stessa piu' volte,
    fino a quando non si giunge alla fine della dichiarazione o se si incontra
    uno stop, inaspettato o meno,  dell'esecuzione.
    Invece, per quelle dichiarazioni che non hanno risultati da ritornare, 
    come INSERT, UPDATE o DELETE serve una singola invocazione sqlite3_step().
    */
  
    if (sqlite3_step(stmt) == SQLITE_DONE)
        printf("... Statement successfully executed: %s\n", sql_str);

    /* Allorquando la funzione sqlite3_step() ritorna SQLITE_DONE, cio' sta a
    significare che la 'Prepared Statement' e' stata eseguita con successo,
    per cui ora ci si trova di fronte a due strade:
    - eseguire nuovamente la dichiarazione resettando la 'Prepared Statement';
    - rilasciare definitivamene la 'Prepared Statement'.
    Nel caso specifico, poiche' non c'è alcuna dichiarazione da ri-eseguire, si
    propende per l'eliminazione definitiva di tutte le risorse legate alla
    'Prepared Statement' appena eseguita, mediante sqlite3_finalize(). */
    if (sqlite3_finalize(stmt) == SQLITE_OK)
        puts("... Prepared Statemend destroyed.");

    // Close database connection
    if (sqlite3_close_v2(db) == SQLITE_OK)
        puts("... Closed database connection. ");

    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

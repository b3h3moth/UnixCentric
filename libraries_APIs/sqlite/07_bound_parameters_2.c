#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di associare, mediante le funzioni della
famiglia 'sqlite3_bind_*()', alcuni parametri a dei valori e incapsularli nella 
stringa SQL da passare al database, tali valori sono forniti in input. 
Infine, stampa a video diverse peculiarita' dei 'bound parameters'. */

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    int flags = SQLITE_OPEN_READWRITE;
    int rc = 0;
    int idx = -1;

    char *sql_str = "INSERT INTO addressbook (fullname, alias, email)"
                    "VALUES(:name, :aka, :mail)";

    if (argc != 5) {
        fprintf(stderr, "Usage: %s dbname, name, alias, email\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Stringhe da associare ai parametri, sono gestite in modo sicuro facendo
    attenzione alla grandezza di ciascuna di esse */
    const char *const str_fullname = argv[2];
    const char *const str_alias = argv[3];
    const char *const str_email = argv[4];

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
    idx = sqlite3_bind_parameter_index(stmt, ":name");
    rc = sqlite3_bind_text(stmt, idx, str_fullname, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Binding the value (%i).\n", rc);
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Bind the second value
    idx = sqlite3_bind_parameter_index(stmt, ":aka");
    rc = sqlite3_bind_text(stmt, idx, str_alias, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Binding the value (%i).\n", rc);
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    // Bind the third value
    idx = sqlite3_bind_parameter_index(stmt, ":mail");
    rc = sqlite3_bind_text(stmt, idx, str_email, -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Binding the value (%i).\n", rc);
        sqlite3_close(db);
        exit(EXIT_FAILURE);
    }

    /* Stampa del totale dei parametri, del nome degli stessi e del 
    rispettivo indice, mediante le funzioni specifiche */
    printf("Total bound parameters: %d\n", sqlite3_bind_parameter_count(stmt));
    
    printf("\'%5s\' index \'%d\'\n", sqlite3_bind_parameter_name(stmt, 1), \
            sqlite3_bind_parameter_index(stmt, ":name"));
    printf("\'%5s\' index \'%d\'\n", sqlite3_bind_parameter_name(stmt, 2), \
            sqlite3_bind_parameter_index(stmt, ":aka"));
    printf("\'%5s\' index \'%d\'\n", sqlite3_bind_parameter_name(stmt, 3), \
            sqlite3_bind_parameter_index(stmt, ":mail"));

    // Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Err. Stepping through the statement.\n");
    } else
        puts("... Statement successfully executed.");

    // Release prepared statement resources
    sqlite3_finalize(stmt);
    // Close database connection
    sqlite3_close_v2(db);
    // Shutdown library initialization
    sqlite3_shutdown();

    return(EXIT_SUCCESS);
}

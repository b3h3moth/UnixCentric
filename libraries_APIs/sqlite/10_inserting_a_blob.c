#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di inserire all'interno di un database una
immagine - tipo di dato blob - ottenuta in input. */

int main(int argc, char *argv[]) {
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    FILE *fp = NULL;
    int flags = SQLITE_OPEN_READWRITE;
    long flen = 0;
    int size = 0;
    int rc = 0;
    char *sql = "CREATE TABLE IF NOT EXISTS blobs("
                "id INTEGER PRIMARY KEY, data BLOB);"
                "INSERT INTO blobs(data) VALUES (?);";

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Per i tipi di dato 'blob' si deve lavorare con file binary
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Err. Cannot open image: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Sposta il 'file position indicator' alla fine del file, sara' utile per
    calcolare il peso dell'immagine, dopodiche' si verifica che il risultato
    sia privo di errori. */
    fseek(fp, 0, SEEK_END);

    if (ferror(fp)) {
        fprintf(stderr, "Err. fseek() failed.\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    /* La funzione ftell() ritorna la posizione corrente del 'file position
    indicator', che corrisponde anche al numero di byte del file. */
    flen = ftell(fp);

    if (flen == -1) {
        fprintf(stderr, "Err. ftell() failed: %s\n", strerror(errno));
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // Riporta il 'file position indicator' all'inizio del file
    fseek(fp, 0, SEEK_SET);

    // L'array che conterra' l'immagine
    char image[flen+1];

    // Lettura dal file pointer e inizializzazione dell'array
    size = fread(image, 1, flen, fp);

    if (ferror(fp)) {
        fprintf(stderr, "Err. fread() failed: %s\n", strerror(errno));
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    // Chiusura del file handler
    fclose(fp);

    // Apertura della connessione al database e verifica di eventuali errori
    rc = sqlite3_open_v2("new.db", &db, flags, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Cannot open db: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_SUCCESS);
    }

    // Creazione della 'prepared statement'
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Prepared Statement creation failed: %s\n", \
                sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_SUCCESS);
    }

    // bind del valore binario - l'immagine - alla 'prepared statement'
    sqlite3_bind_blob(stmt, 1, image, size, SQLITE_STATIC);
    
    // Esecuzione della 'prepared statement' e scrittura dei dati
    rc = sqlite3_step(stmt);
    
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Err. Prepared Statement execution failed: %s", \
                sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

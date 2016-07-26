#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sqlite3.h>

enum {DATA_SIZE = 1024};

/* Lo scopo del programma e' di inserire all'interno di un database una
immagine - tipo di dato blob - ottenuta in input. */

int main(int argc, char *argv[]) {
    sqlite3        *db = NULL;
    sqlite3_stmt   *stmt = NULL;
    sqlite3_blob   *blob = NULL;
    sqlite3_int64  row_id = 0;
    FILE           *fp = NULL;
    int            flags_create = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;
    long           flen = 0;
    int            rc = 0;
    int            bytes_read = 0;
    int            offset = 0;
    void           *data = NULL;
    char           *err_msg = NULL;
    char           *sql_create = "CREATE TABLE IF NOT EXISTS blobs(" \
                                 "id INTEGER PRIMARY KEY, data BLOB);";
    char           *sql_insert = "INSERT INTO blobs(data) VALUES (?);";

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

    // Creazione del database
    rc = sqlite3_open_v2("new.db", &db, flags_create, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Cannot open db: %d-%s\n", \
                rc, sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_SUCCESS);
    }

    // Creazione della tabella mediante il 'convenience wrapper'
    rc = sqlite3_exec(db, sql_create, NULL, NULL, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Cannot create table: %d-%s\n", \
                rc, sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_SUCCESS);
    }

    // Creazione della 'prepared statement' per l'inserimento
    rc = sqlite3_prepare_v2(db, sql_insert, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Prepared Statement creation failed: %d-%s\n", \
                rc, sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_SUCCESS);
    }

    /* Creazione di un blob vuoto i cui byte sono tutti settati a 0x00 - 
    zero-filled blob -, nel quale leggere o scrivere il file binario; in
    questo caso l'interfaccia sara' usata per scrivere l'immagine.  */
    sqlite3_bind_zeroblob(stmt, 1, flen);

    // esecuzione della 'prepared statement' e scrittura 
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Err. Ins. Statement failed: %d-%s\n", \
                rc, sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }

    /* Crea una riga con il dato blog in bianco, sara' utile per la successiva
    chiamata */
    row_id = sqlite3_last_insert_rowid(db);

    // Apertura di un 'BLOB Handle' su 'blob'
    rc = sqlite3_blob_open(db, "main", "blobs", "data", row_id, 1, &blob);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. BLOB Handling failed: %d-%s\n", \
                rc, sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }

    data = malloc(DATA_SIZE);

    // Scrive i dati binari di tipo BLOB nella tabella
    while ((bytes_read = fread(data, 1, DATA_SIZE, fp))) {
        rc = sqlite3_blob_write(blob, data, bytes_read, offset);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "Err. Writing BLOB: %d-%s\n", \
                    rc, sqlite3_errmsg(db));
            exit(EXIT_FAILURE);
        }
        offset += bytes_read;
    }
    
    sqlite3_blob_close(blob);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    printf("BLOB data \'%s\' written\n", argv[1]);
    

    fclose(fp);
    free(data);

    return(EXIT_SUCCESS);
}

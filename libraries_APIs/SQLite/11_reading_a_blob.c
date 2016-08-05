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
    int            flags_create = SQLITE_OPEN_READWRITE;
    long           flen = 0;
    int            rc = 0;
    int            bytes_read = 0;
    int            offset = 0;
    void           *data = NULL;
    char           *err_msg = NULL;
    char           *sql = "SELECT data FROM blobs";

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <db name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen("test.jpg", "wb");
    if (fp == NULL) {
        puts("cannot open");
        return 1;
    }

    // Creazione del database
    rc = sqlite3_open_v2(argv[1], &db, flags_create, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Cannot open db: %d-%s\n", \
                rc, sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_SUCCESS);
    }

    // Creazione della 'prepared statement' per l'inserimento
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Prepared Statement creation failed: %d-%s\n", \
                rc, sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(EXIT_SUCCESS);
    }

    // esecuzione della 'prepared statement' e scrittura 
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Err. Ins. Statement failed: %d-%s\n", \
                rc, sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }

    // Apertura di un 'BLOB Handle' su 'blob'
    rc = sqlite3_blob_open(db, "main", "blobs", "data", row_id, 1, &blob);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. BLOB Handling failed: %d-%s\n", \
                rc, sqlite3_errmsg(db));
        exit(EXIT_FAILURE);
    }

    data = malloc(DATA_SIZE);

    // Scrive i dati binari di tipo BLOB
    while ((bytes_read = fread(data, 1, DATA_SIZE, fp))) {
        rc = sqlite3_blob_read(blob, data, bytes_read, offset);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "Err. Writing BLOB: %d-%s\n", \
                    rc, sqlite3_errmsg(db));
            exit(EXIT_FAILURE);
        }
        offset += bytes_read;
    }

    // Il totale dei byte scritti, ovvero il peso del dato binario
    int file_size = sqlite3_blob_bytes(blob);
     
    sqlite3_blob_close(blob);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    printf("DB: \'%s\'\nBLOB data: \'%s\' | %d byte\n", \
            argv[1], argv[2], file_size);

    fclose(fp);
    free(data);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sqlite3.h>

enum {DATA_SIZE = 1024};

/* Lo scopo del programma e' di inserire all'interno di un database una
immagine - tipo di dato blob - ottenuta in input. */

int main(int argc, char *argv[]) {
    sqlite3        *db = NULL;
    sqlite3_stmt   *stmt = NULL;
    sqlite3_blob   *blob = NULL;
    int           fd = 0;
    int            flags_create = SQLITE_OPEN_READWRITE;
    int            rc = 0;
    char           *sql = "SELECT * FROM blobs where id = 1";


    // Creazione del database
    rc = sqlite3_open_v2("db.db", &db, flags_create, NULL);

    unsigned char **pzBlob = 0;
    int *pnBlob = 0;
    fd = open("bea.jpg", O_WRONLY | O_CREAT, 755);

    do {

    // Creazione della 'prepared statement' per l'inserimento
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    // esecuzione della 'prepared statement' e scrittura 
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        *pnBlob = sqlite3_column_bytes(stmt, 0);
        *pzBlob = (unsigned char *)malloc(*pnBlob);
        memcpy(*pzBlob, (void *)sqlite3_column_blob(stmt, 0), *pnBlob);
    }

    sqlite3_finalize(stmt);
    } while (rc == SQLITE_SCHEMA);

    write(fd, "bea.jpg", *pnBlob);

    sqlite3_close(db);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sqlite3.h>


int main(int argc, char *argv[]) {
    // Connessione al database
    sqlite3        *db = NULL;
    // 1 = scrivere BLOB nel DB | 0 = leggere BLOB dal DB
    bool is_write = 0; 
    // Il file descriptor
    int fd = 0;
    // Il risultato delle chiamate
    int rc = 0;
    // Datbase flags
    int flags = SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE;
    // Il peso del file da inserire nel database
    struct stat file_size = {0};
    // Il peso del tipo di dato blob
    int blob_size = 0;
    // Salva il tipo di dato blob
    unsigned char *data_blob = NULL;
    // Il filename del database
    char const *file_db = NULL;
    // Il file da scrivere nel database o da leggere dal database stesso
    char const *file_wr = NULL;

    // Verifica gli argomenti della linea di comando
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [DB name] (write | read) [FILE]\n", argv[0]);
        return 1;
    }

    file_db = argv[1];
    file_wr = argv[3];

    /* Verifica la prima lettera del terzo argomento, nel caso di esito 
    positivo si imposta la variabile is_write ad 1, ovvero che si procedera'
    alla scrittura di un dato binario nel database.  */
    if (argv[2][0] == 's' || argv[2][0] == 'S') {
        is_write = 1;
    }

    // Apre una connessione al database
    rc = sqlite3_open_v2(file_db, &db, flags, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Err. Open Database Connection failed: %d - %s\n", \
                sqlite3_errcode(db), sqlite3_errmsg(db));
        return 1;
    }

    if (is_write) {
    }

    return(EXIT_SUCCESS);
}

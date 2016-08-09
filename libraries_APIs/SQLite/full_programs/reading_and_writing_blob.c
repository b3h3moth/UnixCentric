#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sqlite3.h>

// Function Prototypes
static int create_table(sqlite3 *db);
static int read_blob(sqlite3 *db, const char *fname, unsigned char **buf_ptr, int *buf_len);
static int write_blob(sqlite3* db, const char *fname, void *buf_ptr, int buf_len);

/* Lo scopo del programma e' di scrivere un dato binario di tipo BLOB nel
database, oppure leggere dal database stesso un BLOB e salvarlo nel
file system. */

int main(int argc, char *argv[]) {
    // Connessione al database
    sqlite3        *db = NULL;
    // 1 = scrivere BLOB nel DB | 0 = leggere BLOB dal DB
    bool is_write = 0; 
    // Il file pointer
    FILE *fp = NULL;
    // Il risultato delle chiamate
    int rc = 0;
    // Datbase flags
    int flags = SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE;
    // Il peso del file da inserire nel database
    struct stat fstatus = {0};
    // Il peso del tipo di dato blob
    int blob_size = 0;
    // Salva il tipo di dato blob
    unsigned char *blob_data = NULL;
    // Il filename del database
    char const *db_filename = NULL;
    // Il file da scrivere nel database o da leggere dal database stesso
    char const *input_file = NULL;

    // Verifica gli argomenti della linea di comando
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [DB name] (write | read) [FILE]\n", argv[0]);
        return 1;
    }

    db_filename = argv[1];
    input_file = argv[3];

    /* Verifica la prima lettera del terzo argomento corrisponda alla 's' o 'S'
    di 'store'; nel caso di esito positivo imposta la variabile 'is_write' a 1,
    ovvero si procedera' alla scrittura di un dato binario nel database.  */
    if (argv[2][0] == 's' || argv[2][0] == 'S') {
        is_write = 1;
    }

    // Apre una connessione al database
    rc = sqlite3_open_v2(db_filename, &db, flags, NULL);
    if (rc != SQLITE_OK) {
            fprintf(stderr, "%d: Open database failed (%d: \'%s\')\n", \
                __LINE__, sqlite3_errcode(db), sqlite3_errmsg(db));
        return 1;
    }

    if (is_write) { // Scrive il tipo di dato BLOB nel database
        create_table(db);

        // Apre il file ricevuto come argomento in lettura
        fp = fopen(input_file, "r");
        if (fp == NULL) {
            fprintf(stderr, "%d: Open file failed (%s: \'%s\')\n", \
                    __LINE__, strerror(errno), input_file);
            return 1;
        }

        if (fstat(fp, &fstatus) != 0) {
            fprintf(stderr, "%d: Stat file failed (%s : \'%s\')\n", \
                    __LINE__, strerror(errno), input_file);
            return 1;
        }

        // Salva in 'blob_size' il peso del file in byte
        blob_size = fstatus.st_size;

        // Alloca lo spazio necessario per il dato blob
        blob_data = malloc(blob_size);
        
        // Legge il file in 'blob_data'
        if (blob_size != read(fd, blob_data, blob_size)) {
            fprintf(stderr, "%d: Read file failed (%s: \'%s\')\n", \
                    __LINE__, strerror(errno), blob_data);
            return 1;
        }

        // Scrive il tipo di dato BLOB nel database
        if (SQLITE_OK != write_blob(db, input_file, blob_data, blob_size)) {
            fprintf(stderr, "%d: Write BLOB into database (%d: \'%s\')\n", \
                    __LINE__, sqlite3_errcode(db), sqlite3_errmsg(db));
            return 1;
        } else
            printf("BLOB data \'%s\' successfully written.\n", input_file);

        /* Rilascia la memoria precedentemente allocata e chiusura del 
        file descriptor */
        free(blob_data);
        close(fd);

    } else { // Legge il tipo di dato BLOB dal database

        // Apre il file in scrittura
        fd = open(input_file, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
        if (fd < 0) {
            fprintf(stderr, "%d: Open file failed (%s: \'%s\')\n", \
                    __LINE__, strerror(errno), input_file);
            return 1;
        }

        // Legge il dato BLOB dal database.
        if (SQLITE_OK != read_blob(db, input_file, &blob_data, &blob_size)) {
            fprintf(stderr, "%d: Write BLOB into database (%d: \'%s\')\n", \
                    __LINE__, sqlite3_errcode(db), sqlite3_errmsg(db));
            return 1;
        }

        // Verifica se il database contiene record o meno
        if (!blob_data) {
            fprintf(stderr, "Ops! Database is empty.\n");
            return 1;
        }

        // Scrive un dato BLOB prelevato dal database in un file
        if (blob_size != write(fd, blob_data, blob_size)) {
            fprintf(stderr, "%d: Write file failed (%s: \'%s\')\n", \
                    __LINE__, strerror(errno), blob_data);
            return 1;
        }

        /* Rilascia la memoria precedentemente allocata, e chiusura del 
        file descriptor */
        free(blob_data);
        close(fd);
    }

    // Chiusura della connessione al database
    if (sqlite3_close_v2(db) == SQLITE_OK)
        puts("Closed database connection");

    return(EXIT_SUCCESS);
}

// Crea la tabella nel database 'db'
static int create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE blobs(file_name TEXT PRIMARY KEY, data BLOB)";
    return sqlite3_exec(db, sql, 0, 0, 0);
}

// Scrive il tipo BLOB nel database
static int write_blob(sqlite3* db, const char *fname, void *buf_ptr, int buf_len) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO blobs(file_name, data) VALUES(?, ?)";
    int rc;

    // Compilazione della Prepared Statement nella macchina virtuale
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "%d: Statement preparation failed (%d: \'%s\')\n", \
                __LINE__, sqlite3_errcode(db), sqlite3_errmsg(db));
        return rc;
    }

    // binding dei valori alle variabili della query SQL
    sqlite3_bind_text(stmt, 1, fname, -1, SQLITE_STATIC);
    sqlite3_bind_blob(stmt, 2, buf_ptr, buf_len, SQLITE_STATIC);

    // Esecuzione della macchina virtuale
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "%d: SQL statement execution failed (%d: \'%s\')\n", \
                __LINE__, sqlite3_errcode(db), sqlite3_errmsg(db));
        return 1;
    }

    // Rilascio delle risorse dedicate alla Prepared Statement
    rc = sqlite3_finalize(stmt);

    return rc;
}

// Legge il tipo di dato BLOB dat database
static int read_blob(sqlite3 *db, const char *fname, unsigned char **buf_ptr, int *buf_len) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT data FROM blobs WHERE file_name = ?";
    int rc;

    // Nel caso non ci fossero record nella tabella
    *buf_ptr = 0;
    *buf_len = 0;
    
    // Compilazione della Prepared Statement nella macchina virtuale
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "%d: Statement preparation failed (%d: \'%s\')\n", \
                __LINE__, sqlite3_errcode(db), sqlite3_errmsg(db));
        return rc;
    }

    // Bind del nome del file alla variabile della query SQL
    sqlite3_bind_text(stmt, 1, fname, -1, SQLITE_STATIC);

    // Esecuzione della macchina virtuale
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW) {
        fprintf(stderr, "%d: SQL statement execution failed (%d: \'%s\')\n", \
                __LINE__, sqlite3_errcode(db), sqlite3_errmsg(db));
        return 1;
    } else {
        *buf_len = sqlite3_column_bytes(stmt, 0);
        *buf_ptr = (unsigned char *)malloc(*buf_len);
        memcpy(*buf_ptr, (void *)sqlite3_column_blob(stmt, 0), *buf_len);
    }

    // Rilascio delle risorse dedicate alla Prepared Statement
    rc = sqlite3_finalize(stmt);

    return rc;
}

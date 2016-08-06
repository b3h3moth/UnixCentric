#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sqlite3.h>


int main(int argc, char *argv[]) {
    // Connessione al database
    sqlite3        *db = NULL;
    // Il filename del database
    char const *file_db = NULL;
    // Il file da scrivere nel database o da leggere dal database stesso
    char const *file_wr = NULL;
    // 1 = salvare; 0 = recuperare
    int is_store = 0; 
    // Il file descriptor
    int fd = 0;
    // Il peso del file da inserire nel database
    struct stat file_size = {0};
    // Il peso del tipo di dato blob
    int blob_size = 0;
    // Salva il tipo di dato blob
    unsigned char *data_blob = NULL;

    // Verifica gli argomenti della linea di comando
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [DB name] (write | read) [FILE]\n", argv[0]);
        return 1;
    }

    file_db = argv[1];
    file_wr = argv[3];

    return(EXIT_SUCCESS);
}

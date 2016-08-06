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
    char const *db_filename = NULL;
    // Il file da salvare o da recuperare dal database
    char const *sr_file = NULL;
    // 1 = salvare; 0 = recuperare
    int is_store = 0; 
    // Il file descriptor
    int fd = 0;
    // Il peso del file da inserire nel database
    struct stat file_size = {0};
    // Il peso del tipo di dato blob
    int blob_size = 0;
    unsigned char *z_blob = NULL;

    return(EXIT_SUCCESS);
}

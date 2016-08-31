#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int ch;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* La funzione feof() ritorna un valore diverso da zero se e' stata tentata
    una lettura dello stream oltre le fine del file, ovvero se l'indicatore di
    fine del file relativo allo stream e' attivo. 
    
    La costante EOF e' definita in nella librera stdio.h ed e' un 
    unsigned char che vale -1.

    La funzione feof() non controlla esplicitamente il raggiungimento della 
    fine del file.

    Questo codice porta ad elaborare due volte la fine del file, e' un errore
    logico molto comune:
        while (!feof(stream)) {
            c = getchar();
        }
    */
    do { 
        ch = fgetc(fp);
    } while (ch != EOF);

    if (feof(fp)) {
        // Handle end of file
    } else if (ferror(fp)) {
        // Handle file error
    } else 
        // handle error
    
    fclose(fp);

    return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp != NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* La funzione feof() ritorna un valore diverso da zero se e' stata tentata
    una lettura dello stream oltre le fine del file. La feof() non controlla
    esplicitamente il raggiungimento della fine del file, ma piuttosto essa 
    si limita a ritornare il valore di una variabile conservata nella libreria
    I/O indicante che e' stata gia' tentata una lettura oltre la fine del file.
    
    Tale variabile non e' impostata da feof() ma da una funzione qualsiasi che
    effettua una lettura oltre la fine del file.
    
    Un errore logico comune e':
        while (!feof(stream)) {
            ...
        }
    Questo codice porta ad elaborare due volte la fine del file.
    */

    
    fclose(fp);
    return(EXIT_SUCCESS);
}

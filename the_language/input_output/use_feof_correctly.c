#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;

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
    */
    
    fclose(fp);
    return(EXIT_SUCCESS);
}

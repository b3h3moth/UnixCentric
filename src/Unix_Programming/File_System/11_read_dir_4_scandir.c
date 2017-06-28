#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

/* Lo scopo del programma e' di fornire la lista dei file di una directory, 
ottenuta in input come paramentro, in modo ordinato, grazie all'utilizzo della 
funzione scandir() */

int main(int argc, char *argv[]) {
    int num_entry, i;
    struct dirent **namelist;

    if (argc < 2) {
       fprintf(stderr, "Uso: %s <dirname>\n", argv[0]);
       exit(EXIT_FAILURE);
    }

    num_entry = scandir(argv[1], &namelist, NULL, alphasort);
    if (num_entry < 0) {
        fprintf(stderr, "Err.: %d scandir(); %s\n", errno, strerror(errno));
        return(EXIT_FAILURE);
    } else {
        for (i = 0; i < num_entry; i++) {
            printf("%s\n", namelist[i]->d_name);
            free(namelist[i]);
        }
    }

    /* Poiche' si tratta di un puntatore a un array di directory e' buona
    norma rilasciare la memoria sia di ciascun elemento dell'array sia del 
    puntatore stesso .*/    
    free(namelist);

    exit(EXIT_SUCCESS);
}

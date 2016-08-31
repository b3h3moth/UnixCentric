#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *default_string = "Take a walk on the wild side";
    char *ptr = default_string;

    int defstr_size  = 0;
    char *bkp_copy = NULL;

    // Conta il numero dei caratteri della stringa
    while ( *ptr++ != '\0')
        defstr_size++;

    printf("Size of the default string: %d\n", defstr_size);

    // Alloca lo spazio necessario per contenere la stringa da copiare
    bkp_copy = malloc(defstr_size + 1);

    // Inserisce il 'null terminator character' alla fine della stringa
    bkp_copy[defstr_size] = '\0';

    /* Copia ciascun carattere di una stringa nell'altra, facendo attenzione a
       a far pountare il puntatore di 'appoggio' all'inizio della stringa da
       copiare */
    ptr = default_string;
    int i=0;
    while (*ptr != '\0')
        bkp_copy[i++] = *ptr++;

    printf("Def.str: %s (%d byte)\n", default_string, strlen(default_string));
    printf("Bkp-str: %s (%d byte)\n", bkp_copy, strlen(bkp_copy));

    return(EXIT_SUCCESS);
}

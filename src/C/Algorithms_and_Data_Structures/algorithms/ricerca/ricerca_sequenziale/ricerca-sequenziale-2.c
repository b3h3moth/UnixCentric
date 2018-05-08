#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 20

int lookup(char *word, char *array[]);

int main(int argc, char *argv[]) {
    char str_input[MAX_STR];

    char *flab[] = {
        "O'Reilly",
        "Wrox",
        "Elsevier",
        "Pearson",
        "Apogeo",
        "Sams",
        NULL
    };

    printf("String: ");

    /* Stringa da cercare all'interno dell'array */
    scanf("%s", str_input);

    int test = lookup(str_input, flab);

    if (test >= 0)
        puts("stringa trovata");
    else
        puts("stringa non trovata");


    return(EXIT_SUCCESS);
}

/* Ricerca sequenziale di parole in un array, detta anche ricerca lineare.

   L'algoritmo della ricerca sequenziale e' così definito perche' controlla 
ciascun elemento al fine di verificare la corrispondenza con l'elemento
desiderato. 

Il tempo di esecuzione e' lineare rispetto alla dimensione dei dati, ovvero al
mutare del numero dei dati mutera' anche il tempo impiegato per la ricerca. */
int lookup(char *word, char *array[])
{
    int i;

    for (i=0; array[i] != NULL; i++)
        if (strcmp(word, array[i]) == 0)
            return i;

    return(-1);
}

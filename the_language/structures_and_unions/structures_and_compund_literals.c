#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUT_LEN 20
#define MAX_TIT_LEN 40

struct library {
    int id;
    char author[MAX_AUT_LEN];
    char title[MAX_TIT_LEN];
};

int main(void) {
    // Inizializzazione di una struttura con un compound literals
    struct library data = (struct library){1, "XXlliam XXbson", "XXuromancer"};

    printf("id: %d\tauthor: %s\ttitle: %s\n", data.id, data.author, data.title);

    /* Si provvedere alla riscrittura di 'author' e 'title', utilizzando
    questa volta i 'compund literals' come parametri della funzione strcpy() */
    strcpy(data.author, (const char[]){"WIlliam Gibson"});
    strcpy(data.title, (const char[]){"Neuromancer"});

    printf("id: %d\tauthor: %s\ttitle: %s\n", data.id, data.author, data.title);
    
    return(EXIT_SUCCESS);
}

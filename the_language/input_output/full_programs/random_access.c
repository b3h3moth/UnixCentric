#include <stdio.h>
#include <stdlib.h>

// Struttura anonima per salvataggio di dati globali, quali il nome del file
struct {
    char *filename;
    FILE *fp;
} global = { .filename = "data.bin", .fp = NULL };

int main(void) {
    return(EXIT_SUCCESS);
}

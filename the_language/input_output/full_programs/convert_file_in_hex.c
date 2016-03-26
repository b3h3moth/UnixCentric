#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

int main(void) {
    char *filename[FILENAME_MAX]; // Definito in stdio.h
    FILE *fp;

    if (argc == 1) {
        // Inserimento del nome del file
        fputs("Enter filename: ", stdout);
        fgets(filename, MAXLEN, stdin);

        //
    return(EXIT_SUCCESS);
}

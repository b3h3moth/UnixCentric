#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>

enum { BUF_LEN = 64 };

/* Lo scopo del programma e' di estrapolare da un path solo il filename finale,
estensione compresa */

int main(int argc, char *argv[]) {
    char default_path[] = "/home/user/photo/2016/summer/peace_and_love.jpg";
    char filename[BUF_LEN];
    char img_type[4];

    printf("Default string: %s (%2d byte)\n", default_path, strlen(default_path));

    // Salva il nome del file in 'filename', togliendo tutte le directory
    snprintf(filename, BUF_LEN, "%s", basename(default_path));

    printf("%18s (%2d byte)\n", filename, strlen(filename));

    /* Preleva l'estensione da 'filename' e la salva in 'img_type'
    
    Nota: Nella seconda chiamata a strtok(), poiche' si riferisce alla
          stessa stringa, si inserisce NULL */
    strtok(filename, ".");
    snprintf(img_type, 4, "%s", strtok(NULL, "."));

    printf("%18s (%2d byte)\n", filename, strlen(filename));
    printf("%18s (%2d byte)\n", img_type, strlen(img_type));

    return(EXIT_SUCCESS);
}

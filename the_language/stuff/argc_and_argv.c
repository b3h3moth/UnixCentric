#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' di porre le basi per la scrittura di un menu'
senza l'ausilio di funzioni quali possono essere getopt() o getopt_long() */

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s -a -b\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Cicla tra gli argomenti verificando che il primo carattere di ciascun
    argomento sia '-' */
    for (int i=1; i<argc; i++) {
        if (argv[i][0] != '-')
            break;

        switch (argv[i][1]) {
            case 'a':
                printf("Full option is: %s\n", argv[i]);
                fputs("Do something\n", stdout);
                break;
            case 'b':
                printf("Full option is: %s\n", argv[i]);
                fputs("Do something\n", stdout);
                break;
            default:
                printf("Usage: %s -a -b\n", argv[0]);
        }

    }

    exit(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' di porre le basi per la scrittura di un menu'
senza l'ausilio di funzioni quali possono essere getopt() o getopt_long() */

int main(int argc, char *argv[]) {

    /* Cicla tra gli argomenti verificando che il primo carattere di ciascun
    argomento sia '-' */
    for (int i=1; i<argc; i++) {
        if (argv[i][0] != '-')
            break;


        switch (argv[i][1]) {
            case 'o':
                printf("%c\n", argv[i][1]);
                printf("output = %s (err.)\n", argv[i]);
                printf("output = %s (good)\n", &argv[i][2]);
                break;
            case 'f':
                printf("from = %d (err.)\n", atoi(argv[i]));
                printf("from = %d (good)\n", atoi(&argv[i][2]));
                break;
        }

    }

    exit(EXIT_SUCCESS);
}

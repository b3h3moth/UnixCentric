#include <stdio.h>
#include <stdlib.h>

/* Lo scopo del programma e' le realizzazione di un vettore di stringhe e
successivamente assegnare solo specifici elementi a un vettore di puntatori
a stringhe */

int main(void) {
    char *unixos[] = { 
        "OpenBSD",
        "FreeBSD",
        "Open Solaris",
        "NetBSD",
        "AIX",
        "GNU/Linux Os",
        "HP/UX",
        "Dragonfly BSD",
    };

    /* Array di puntatori a puntatori a char contenenti solo le voci di OS
    UNIX di tipo BSD, o meglio, gli indirizzi delle voci, in modo tale da non
    occupare spazio indesiderato.  */
    char **bsd_os[4] = { &unixos[0], &unixos[1] };
    bsd_os[2] = &unixos[3];
    bsd_os[3] = &unixos[7];

    // Stampa ciascun membro del nuovo array di puntatori a puntatori a char
    for (int i=0; i<sizeof(**bsd_os)/sizeof(**bsd_os[0]); i++)
        printf("%s\n", *bsd_os[i]);

    return(EXIT_SUCCESS);
}

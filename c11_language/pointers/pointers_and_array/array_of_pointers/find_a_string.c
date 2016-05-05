#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lookup_os(char const *const osname, char const *oslist[], int const size);

/* Lo scopo del programma e' di realizzare un array di puntatori, sul quale
eseguire una ricerca mediante una funzione. */

int main(void) {
    char const *unixos[] = {
        "OpenBSD",
        "FreeBSD",
        "Debian",
        "Gentoo",
        "Arch",
        "Solaris",
        NULL
    };

    int res = lookup_os("Solaris", unixos, 6);

    if (res != -1)
        printf("%s\n", unixos[res]);
    else
        puts("That OS is not in the list, sorry.");
    
    return(EXIT_SUCCESS);
}

/* Ricerca la stringa 'osname' nell'array di puntatori 'unixos'. In caso di 
esito positivo ritorna l'indice dell'array che fa riferimento alla stringa, 
altrimenti -1. */
int lookup_os(char const *const osname, char const *oslist[], int const size) {
    char const **osp;

    for (osp = oslist; osp < oslist + size; osp++) {
        if (strcmp(osname, *osp) == 0)
            return osp - oslist;
    }

    return(-1);
}

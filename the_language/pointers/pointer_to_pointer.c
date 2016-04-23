#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *unixos[] = { 
        "OpenBSD",
        "FreeBSD",
        "Open Solaris",
        "NetBSD",
        "AIX",
        "GNU/Linux Os",
        "HP/UX",
    };

    // Array di puntatori contenenti solo le voci di OS UNIX di tipo BSD
    char *bsd_os[3] = { unixos[0], unixos[1] };
    bsd_os[2] = unixos[3];

    // Dichiarazione ed inizializzazione di un puntatore a un puntatore.
    char **pptr = bsd_os;

    for (int i=0; i<sizeof(bsd_os)/sizeof(bsd_os[0]); i++)
        printf("%s\n", pptr[i]);

    return(EXIT_SUCCESS);
}

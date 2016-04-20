#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *unixos[] = { 
        "OpenBSD",
        "FreeBSD",
        "Open Solaris",
        "AIX",
        "GNU/Linux Os",
        "",
    };

    char *pkwords[6] = { 
        unixos[0], unixos[1], unixos[2], 
        unixos[3], unixos[4], unixos[5]
    };


    char *ppk[] = {pkwords[0], pkwords[1], pkwords[2], pkwords[3], pkwords[4], pkwords[5] };

    char **ptppk = ppk;

    for (int i=0; i<sizeof(ppk)/sizeof(ppk[0]); i++)
        printf("%s\n", ptppk[i]);

    return(EXIT_SUCCESS);
}

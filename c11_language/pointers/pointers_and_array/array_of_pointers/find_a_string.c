#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lookup_os(char const *const osname, char const *oslist[], int const size);

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

    int res = lookup_os("solaris", unixos, 6);

    if (res != -1)
        printf("%s\n", unixos[res]);
    else
        puts("string doesn't find");
    
    return(EXIT_SUCCESS);
}

int lookup_os(char const *const osname, char const *oslist[], int const size) {
    char const **osp;

    for (osp = oslist; osp < oslist + size; osp++) {
        if (strcmp(osname, *osp) == 0)
            return osp - oslist;
    }

    return(-1);
}

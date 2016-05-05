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

    lookup_os("OpenBSD", unixos, 6);
    
    return(EXIT_SUCCESS);
}

int lookup_os(char const *const osname, char const *oslist[], int const size) {
    char const **osp;

    for (osp = oslist; osp != NULL; osp++) {
        if (strcmp(osname, *osp) == 0)
            return osp - oslist;
    }

    return -11;
}

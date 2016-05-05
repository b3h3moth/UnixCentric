#include <stdio.h>
#include <stdlib.h>

int lookup_os(char const *const osname, char const *oslist[], int const size);

int main(void) {
    char const *unixos[] = {
        "OpenBSD",
        "FreeBSD",
        "Debian",
        "Gentoo",
        "Arch",
        "Solaris"
    };
    
    return(EXIT_SUCCESS);
}

int lookup_os(char const *const osname, char const *oslist[], int const size) {

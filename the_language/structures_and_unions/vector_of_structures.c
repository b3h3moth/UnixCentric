#include <stdio.h>
#include <stdlib.h>

#define VEC_SIZE(x)    (sizeof(x)/sizeof(x[0]))

struct unix_systems {
    char *os_name;
    int year;
};

int main(void) {
    // Inizializzazione del vettore di struttore
    const struct unix_systems list_of_unix_os[] = {
        {"OpenBSD",  1994},     {"FreeBSD",    1992},
        {"Linux",  1991},       {"HP/UX",  1995},
        {"AIX",  1994},         {"Open Solaris",  2005},
        {"UnixWare",  1992},    {"Mac OS X",  2000},
        {"NetBSD",  1992},      {"Sun OS", 1981},
        {"Minix",   1987},      {"SCO Unix", 1983}
    };

    for (int i=0; i<VEC_SIZE(list_of_unix_os); i++) {
        ;
    }

    return(EXIT_SUCCESS);
}

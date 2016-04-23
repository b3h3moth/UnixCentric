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

    char *bsd_os[2] = { unixos[0], unixos[1] };

    char *arr_to_ptrs[6] = { 
        unixos[0], unixos[1], unixos[2], unixos[3], unixos[4], unixos[5]
    };

    char **pptr = arr_to_ptrs;

    for (int i=0; i<sizeof(arr_to_ptrs)/sizeof(arr_to_ptrs[0]); i++)
        printf("%s\n", pptr[i]);

    return(EXIT_SUCCESS);
}

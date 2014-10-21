#include <stdio.h>
#include <stdlib.h>
#include <powerpc-linux-gnu/gnu/libc-version.h>

// La libreria in questione, se trovata, fornira' la
// versione della librera GNU C.

int main(void) {
    const char *version = gnu_get_libc_version();

    printf("%s\n", version);

    return(EXIT_SUCCESS);
}

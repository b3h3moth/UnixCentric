#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lo scopo del programma e' di scrivere un intero array all'all'inerno di un
file mediante una sola chiamata, utilizzando la funzione fwrite(). */

int main(void) {
    FILE *fp;
    const char *unix_os[] = { 
        "Debian GNU/Linux", "OpenBSD", "FreeBSD", 
        "HP-UX", "Solaris", "Mac OS X", "NetBSD", 
        "OpenSolaris", "AIX", "Minix"
    };

    fp = fopen("file.txt", "wb");

    fwrite(unix_os, strlen(unix_os[0]), strlen(*unix_os)/strlen(unix_os[0]), fp);

    fclose(fp);


    return(EXIT_SUCCESS);
}

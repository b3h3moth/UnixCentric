#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lo scopo del programma e' di scrivere un intero array all'all'inerno di un
file mediante una sola chiamata, utilizzando la funzione fwrite(). */

int main(void) {
    FILE *fp;
    /*
    const char *unix_os[] = { 
        "Debian GNU/Linux", "OpenBSD", "FreeBSD", 
        "HP-UX", "Solaris", "Mac OS X", "NetBSD", 
        "OpenSolaris", "AIX", "Minix"
    };
    */
    int vec[] = { 1,2,3,4,5,6,7,8,9,10};

    fp = fopen("file.txt", "w");

    fwrite(&vec, sizeof(vec[0]), sizeof(vec)/sizeof(vec[0]), fp);

    fclose(fp);


    return(EXIT_SUCCESS);
}

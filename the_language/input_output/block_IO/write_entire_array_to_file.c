#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN  100

/* Lo scopo del programma e' di inizializzare un array di MAX_LEN elementi 
con un numero casuale, dopodiche' scrivere l'intero array in file binario 
mediante la funzione fwrite() */

int main(void) {
    FILE *fp;
    char *binfile = "data.bin";
    int data[MAX_LEN];

    /*
    const char *unix_os[] = { 
        "Debian GNU/Linux", "OpenBSD", "FreeBSD", 
        "HP-UX", "Solaris", "Mac OS X", "NetBSD", 
        "OpenSolaris", "AIX", "Minix"
    };
    */

    fp = fopen("file.txt", "w");

    fwrite(&vec, sizeof(vec[0]), sizeof(vec)/sizeof(vec[0]), fp);

    fclose(fp);


    return(EXIT_SUCCESS);
}

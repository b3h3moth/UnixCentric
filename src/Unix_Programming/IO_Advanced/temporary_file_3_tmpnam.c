#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 512

/* Lo scopo del programma e' la creazione di un file temporaneo mediante la
funzione tmpnam(). 

Per ragioni di sicurezza consiglia l'uso o di tmpfile() o di mkstemp(). */

int main(int argc, char *argv[]) {
    char buf[MAX_BUF];     
    char tmp_pathname[L_tmpnam];	
    FILE *ftmp;		
  
    /* 
        Oppure con NULL al posto di una stringa
        char *tmpfile = tmpnam(NULL);
    */
    tmpnam(tmp_pathname);

    printf("Temporary file: %s\n", tmp_pathname);

    if ((ftmp = fopen(tmp_pathname, "w+")) == NULL ) { 
        fprintf(stderr, "Err. fopen() failed %s : %s\n", \
                strerror(errno), tmp_pathname);
        exit(EXIT_FAILURE);
    }

    /* Si scrive nel file temporaneo */
    fputs("The art of UNIX programming", ftmp);

    /* Si riporta la posizione corrente all'interno del file all'inizio, per
       poter leggere il file */
    fseek(ftmp, 0L, SEEK_SET);

    /* Si legge dal file temporaneo */
    if (fgets(buf, sizeof(buf), ftmp) == NULL) {
        fprintf(stderr, "Err. fgets() failes %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
   
    fputs(buf, stdout);

    fclose(ftmp);
    
    return(EXIT_SUCCESS);
}

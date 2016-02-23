#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 512

static const char fname[] = "/etc/passwd";

/* Lo scopo del programma e' di impostare il buffer a una dimensione prefissata
e leggere un file 'char by char' */

int main(void) {
    char buf[BUF_SIZE];
    int ch;
    FILE *fp;

    if ((fp = fopen(fname, "r")) == NULL ) {
        fprintf(stderr, "Err. fopen() %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
        
    printf("%s is open.\n", fname);
    
    /* Impostazione del buffer a 'BUF_SIZE', si e' optato per un tipo di
    buffer 'line buffered' ovvero che dev'essere svuotato ad ogni 'new line'
    per l'appunto. Le opzioni sono :
    _IOLBF; line buffered
    _IOFBF; fully
    _IONBF; unbuffered
    */
    if (setvbuf(fp, buf, _IOLBF, BUF_SIZE) != 0) {
        fprintf(stderr, "Err. setvbuf() %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp)) != EOF)
        fputc(ch, stdout);

    fclose(fp);

    return(EXIT_SUCCESS);
}

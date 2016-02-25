#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/utsname.h>

/* Lo scopo del programma e' di scrivere all'interno del file ascii 'filename'
per evitare messaggi di warning dal compilatore sarebbe meglio compilare con
l'opzione _D_BSD_SOURCE */

void set_hostname_info(char *arg, char **vec);

int main(void) {
    struct utsname buf;
    char *hostinfo[3];
    char fname[] = "db.txt";
    FILE *fout;

    if ((fout = fopen(fname, "w")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (uname(&buf) == -1) {
        fprintf(stderr, "Err. uname(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    set_hostname_info(buf.sysname, &hostinfo[0]);
    set_hostname_info(buf.release, &hostinfo[1]);
    set_hostname_info(buf.version, &hostinfo[2]);

    for (int i=0; i<3; i++)
        fprintf(fout, "%s\n", hostinfo[i]);

    fclose(fout);


    return(EXIT_SUCCESS);
}

void set_hostname_info(char *arg, char **vec) {
    if ((*vec = malloc(sizeof(strlen(arg)))) == NULL) {
        fprintf(stderr, "Err. malloc(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    strcpy(*vec, arg);
}

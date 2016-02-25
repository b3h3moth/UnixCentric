#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/utsname.h>

/* Lo scopo del programma e' di scrivere all'interno del file ascii 'filename'
per evitare messaggi di warning dal compilatore sarebbe meglio compilare con
l'opzione _D_BSD_SOURCE */

void set_hostname_info(char *arg, char *vec);

int main(void) {
    struct utsname buf;
    char *hostinfo[3];

    if (uname(&buf) == -1) {
        fprintf(stderr, "Err. uname(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    set_hostname_info(buf.sysname, hostinfo[0]);
/*
    hostinfo[0] = malloc(sizeof(strlen(buf.sysname)));
    hostinfo[1] = malloc(sizeof(strlen(buf.release)));
    hostinfo[2] = malloc(sizeof(strlen(buf.version)));
    strcpy(hostinfo[0], buf.sysname);
    strcpy(hostinfo[1], buf.release);
    strcpy(hostinfo[2], buf.version);
    
    printf(hostinfo[0]);
    printf(hostinfo[1]);
    printf(hostinfo[2]);
*/
    printf(hostinfo[0]);

    return(EXIT_SUCCESS);
}

void set_hostname_info(char *arg, char *vec) {
    vec = malloc(sizeof(strlen(arg)));
    strcpy(vec, arg);
    printf(vec);
    printf(arg);
}

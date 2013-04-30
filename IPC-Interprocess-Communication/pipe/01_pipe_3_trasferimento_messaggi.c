#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 256

/* Si procede alla creazione di una pipe il cui compito e' il trasferimento di
messaggi - stringhe ottenute in input di lunghezza massima predefinita - all'
interno del medesimo processo.
*/

void write_msg(int fd[]);

int main(int argc, char *argv[]) {
    int status;
    int fd[2];

    /* Creazione della pipe */
    if ( (status = pipe(fd)) < 0) {
        fprintf(stderr, "Err.: %d pipe() - %s\n", errno, srerror(errno));
        exit(EXIT_FAILURE);
    }

    write_msg(fd);



    return(EXIT_SUCCESS);
}

void write_msg(int fd[])
{
    int i;
    char buf[MAX_BUF];

    for (i=0; i<3; i++) {
        printf("msg[%d] =", i);
        scanf("%s", buf);

        /* Aggiunge gli spazi bianchi */
        add_tail_blank(buf);

        /* Scrittura nella pipe */
        if (write(fd[0]. buf, MSG_LEN) != MSG_LEN) {
            fprintf(stderr, "Err.: %d write() - %s\n", errno, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
}

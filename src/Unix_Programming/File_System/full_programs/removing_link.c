#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define MODES (O_WRONLY | O_CREAT | O_EXCL)
#define PERMS (S_IRUSR | S_IWUSR)

enum {CMD_SZ=200, BUF_SZ=1024};

/* Lo scopo del programma e' di verificare quando avviene effettivamente la
rimozione di un file, nel caso specifico il file descriptor di un file appena 
creato resta attivo pur avendo rimosso il file stesso mediante una chiamata
ad unlink(). Il file sara' rimosso solo quando tutti i file descriptor
attivi saranno cessati, ossia alla conclusione del processo. */

int main(int argc, char *argv[]) {
    int fd, n_blks;
    char cmd[CMD_SZ];   /* Comando da eseguire via shell */
    char buf[BUF_SZ];   /* Byte da scrivere nel file */

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <tmpfile> [num 1kb blocks]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n_blks = strtol(argv[2], NULL, 10);

    if ((fd = open(argv[1], MODES, PERMS)) == -1) {
        fprintf(stderr, "Err. %d, open() %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Rimozione del file creato */
    if (unlink(argv[1]) == -1) {
        fprintf(stderr, "Err. %d, unlink() %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

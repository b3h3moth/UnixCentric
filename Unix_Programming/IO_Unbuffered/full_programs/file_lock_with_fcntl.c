#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

/* Lo scopo del  programma e' la realizzazione di un file 'write lock'
utilizzando la funzione fcntl().

Tra le operazioni piu' comuni della funzione fcntl() vi e' la possibilita' di 
mettere un blocco in lettura o in scrittura su un file. Il blocco in lettura e'
posto su un file descriptor leggibile, anche in contemporanea tra piu' 
processi; il blocco in scrittura invece va posto su un file descriptor 
scrivibile, ma solo un processo puo' beneficiarne. Il medesimo file non puo' 
essere bloccato sia in lettura sia in scrittura. */

int main(int argc, char *argv[]) {
    struct flock lock;
    int fd = 0;
    char *file = argv[1];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Open file to lock: %s\n", file);

    fd = open(file, O_WRONLY);
    if (fd == -1) {
        fprintf(stderr, "Err. Open file failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Azzeramento della variabile di tipo struct flock 'lock'
    memset(&lock, 0, sizeof(lock));

    // Imposta il tipo del lock in scrittura
    lock.l_type = F_WRLCK;

    // Setta il lock sul file descriptor
    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        fprintf(stderr, "Err. fcntl() failed: %s\n", strerror(errno));
        return 1;
    }

    return(EXIT_SUCCESS);
}

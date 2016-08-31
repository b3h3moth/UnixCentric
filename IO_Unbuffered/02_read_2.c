#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUF 1024

/* Lo scopo del programma e' la lettura di un file definito a 'compile time', 
la stampa a video dello stesso e' affidata alla funzione di libreria 
printf() */

int main(void) {
    char finput[] = "/etc/fstab";
    int fd, nread;
    char buffer[MAX_BUF+1];

    if ((fd = open(finput, O_RDONLY)) < 0) {
       fprintf(stderr,"Err. open file\n");
       exit(EXIT_FAILURE);
    }

    // Legge MAX_BUF byte dal file descriptor 'fd', salvandoli in 'buffer'
    if ((nread = read(fd, buffer, MAX_BUF)) < 0) {
       fprintf(stderr, "Err. read file\n");
       exit(EXIT_FAILURE);
    }

    buffer[nread] = '\0';

    /* Per stampare il contenuto del buffer si utilizza la printf(), che non e'
    efficiente la write() */
    printf("%s", buffer);

    close(fd);

    return(EXIT_SUCCESS);
}

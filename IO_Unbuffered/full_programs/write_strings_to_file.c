#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE	128

// Function Prototype
void write_strings(char b[], int fdw);

/* Lo scopo del programma e' di scrivere una serie di stringhe, mediante la
funzione 'write_strings()', in un file. Le stringhe sono inserite input. */


int main(int argc, char *argv[]){
    char buf[BUF_SIZE];
    int fd1;
    char *filename = "test.txt";

    if ( (fd1 = open(filename, O_WRONLY | O_CREAT, 0755)) < 0) {
       fprintf(stderr, "Err: (%d) - '%s'\n", errno, strerror(errno));
       exit(errno);
    }

    write_strings(buf, fd1);
    
    close(fd1);

    return(EXIT_SUCCESS);
}

void write_strings(char b[], int fdw) {
    int i;
    int n_read;
    printf("Immettere il testo (digitare X per uscire)\n");

    // Clean the buffer
    for (i=0; i<BUF_SIZE; i++)
        b[i] = 0;

    while ((n_read = read(STDIN_FILENO, b, BUF_SIZE)) > 0) {
        if (b[n_read-2] == 'X')
            break;
        
        if (write(fdw, b, n_read) != n_read) {
      	    fprintf(stderr, "Err: (%d) - %s\n", errno, strerror(errno));
            exit(errno);
        }
    }
}

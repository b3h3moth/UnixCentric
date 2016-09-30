#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/* Lo scopo del programma e' di redirigere lo standard output verso un file,
utilizzando una funzione di duplicazione del file descriptor, nel caso 
specifico dup3(). */

int main(void) {
    int fd;
    char *str;
    char filename[] = "fdup.txt";
    int flags = O_WRONLY | O_CREAT;
    int mode = S_IRWXU | S_IXGRP | S_IRWXG | S_IROTH | S_IXOTH;
    
    fd = open(filename, flags, mode);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    /* Copia il file descriptor aperto nello stdout, quindi tutto cio' che
    dovrebbe essere escritto sullo standard output sara' scritto su file */
    if (dup3(fd, 1, O_CLOEXEC) < 0) { 
      perror("dup2"); 
      exit(EXIT_FAILURE);
    }

    /* Con dup3() e' necessario compilare con la macro -D_GNU_SOURCE per 
    evitare messaggi di Warning. */
    
    printf("The standard output goes into \'%s\'.\n", filename);
    
    close(fd);
    
    str = "Where does it go? ... \n";
    
    if (fwrite(str, sizeof(char), strlen(str), stdout) < 0 ) {
        perror("fwrite");
        exit(EXIT_FAILURE);
    } 
    
    fflush(stdout); 

    str = "Ok, Now I'm writing on stdout ... are you sure?\n";
    
    if (write(1, str, strlen(str)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}

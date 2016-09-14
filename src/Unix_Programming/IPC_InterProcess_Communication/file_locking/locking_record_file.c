#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/* Lo scopo del programma e' di accedere in scrittura a un file di caratteri e
modificarne uno in una posizione data; il programma inoltre deve consentire 
l'accesso esclusivo al file, applicando un blocco sulla sola porzione da 
modificare. */

int main(int argc, char *argv[]) {
    int fd;
    struct flock fl;
    char *filename = "test.txt";

    if ((fd = open(filename, O_RDWR|O_CREAT)) == -1) {
        fprintf(stderr, "Uso: %s 'filename'\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    /* Imposta il lock in scrittura */
    fl.l_type = F_WRLCK;		
    fl.l_whence = SEEK_SET;
    
    /* lock in scrittura dal quarto byte ...*/
    fl.l_start = 4;		
    /* ... al sesto byte, ovvero due byte */
    fl.l_len = 2;		

    if (fcntl(fd, F_SETLK, &fl) == -1) {
        printf("Bloccato...");
    } else {
        getchar();
      
        /* Mantiene il blocco */
        lseek(fd, (long)2 * sizeof(char), SEEK_SET);
        
        /* Effettua la modifica ... */
        write(fd,"*", 2);

      	/* ... sblocca la risorsa ... */
        fl.l_type = F_UNLCK;
        fl.l_whence = SEEK_SET;
        fl.l_start = 4;
        fl.l_len = 2;
    }

    close(fd);

   return(EXIT_SUCCESS);
}

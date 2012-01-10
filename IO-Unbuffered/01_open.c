#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/*
 Il termine Unbuffered I/O (definito anche I/O di basso livello) indica che le 
 varie routine (open, read, write, lseek, close, etc...) sono chiamate dirette 
 al sistema operativo e pertanto gestite direttamente dal Kernel; tecnicamente 
 invece indica che l'accesso in lettura e in scrittura sul disco comporta un 
 "semplice" trasferimento di byte, naturalmente senza formattazione.

 L'I/O Unbuffered non e' standard ISO C bensi' standard POSIX 1., nonche' Single
 Unix Specification.
*/

int main(int argc, char *argv[]) {
   int fd;
   char *filename = "/etc/group";
  
   /*
    int open(const char *pathnarme, int oflag, mode_t mode);
    - pathname, il file da aprire o creare;
    - oflag; serie di costanti, tra cui (O_RSONLY, O_WRONLY, O_RDWR, etc...);
    - mode; usato solo se il file e' da creare, riguarda i permessi del file 
    stesso.

    Allorquando si crea/apre un file, il kernel rilascia un file descriptor al
    processo, esso e' un intero non negativo che identifica un file aperto; nei 
    sistemi UNIX ad ogni processo eseguito dalla shell sono associati 3 file
    descriptor: standard input 0, standard output 1, standard error 2.

    POISX peraltro ne specifica anche le costanti simboliche in:
    - standard input  = 0 = STDIN_FILENO;
    - stanbdar output = 1 = STDOUT_FILENO;
    - standard error  = 2 = STDERR_FILENO;

    Per poter iniziare a lavorare con un file e' necessario per prima cosa 
    aprirlo, la open() ha questo compito, ed e' peralto in questo momento che 
    sono associati ad esso anche i 3 file descriptor di default.

    Nell'esempio, e' un file in sola lettura, pertanto non ha bisogno del terzo 
    argomento.
   */
   if ( (fd = open(filename, O_RDONLY)) < 0) {
      fprintf(stderr, "Err. open file\n");
      exit(EXIT_FAILURE);
   }

   /* Lo si chiude subito senza alcuna operazione su di esso */
   close(fd);

   return(EXIT_SUCCESS);
}

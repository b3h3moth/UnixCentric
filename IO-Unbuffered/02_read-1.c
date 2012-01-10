#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <string.h>

#define MAXSTR 1024

int main(int argc, char *argv[], char *envp[])
{
   int fd, rd;
   char filename[] = "/etc/passwd";
   char buf[MAXSTR];

   if ((fd = open(filename, O_RDONLY)) == -1)
      printf("Err.\n");

   if ( (rd = read(fd, buf, MAXSTR)) != -1)
   	 write(fileno(stdout), buf, strlen(buf));

   printf("\n");

   close(fd);

   return(EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF	1

/*
 Il termine Unbuffered I/O (definito anche I/O di basso livello) indica che le 
 varie routine (open, read, write, lseek, close, etc...) sono chiamate dirette 
 al sistema operativo e pertanto gestite direttamente dal Kernel; tecnicamente 
 invece indica che l'accesso in lettura e in scrittura sul disco comporta un 
 "semplice" trasferimento di byte, naturalmente senza formattazione.

 L'I/O Unbuffered non e' standard ISO C bensi' standard POSIX 1., nonche' Single
 Unix Specification.

 Comportamento del programma:
 Il programma richiede l'inserimento del nome di un file in input, utilizzando 
 un path assoluto, dopodiche' tale file sara' inviato allo standard output.
*/

int main(int argc, char *argv[]) {
   int fd, n;
   char buf[MAX_BUF];

   if (argc < 2) {
      fprintf(stderr, "Uso: %s <file name>\n", argv[0]);
      exit(EXIT_FAILURE);
   }
  
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
   if ( (fd = open(argv[1], O_RDONLY)) < 0) {
      fprintf(stderr, "Err. open file\n");
      exit(EXIT_FAILURE);
   }

   /* Scrive il contenuto del file 'filename' in output, un carattere
    * per volta */
   while ((n = read(fd, buf, MAX_BUF)) > 0)
      write (STDOUT_FILENO, buf, n);

   close(fd);
   return(EXIT_SUCCESS);
}

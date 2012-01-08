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

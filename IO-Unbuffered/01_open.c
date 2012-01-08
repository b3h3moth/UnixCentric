#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF	1

/*
 Il termine Unbuffered I/O (I/O di basso livello) indica che le varie routine
 (open, read, write, lseek, close, etc...) sono chiamate dirette al sistema
 operativo, per cui gestite direttamente dal Kernel, tecnicamente invece indica
 che l'accesso in lettura e scrittura sul disco comporta un 'semplice'
 trasferimento di byte, naturalmente nsenza formattazione.

 Non e' standard ISO C ma standard POSIX 1. e Single Unix Specification.
*/

int main() {
   char *filename="/etc/passwd";
   int fd, n;
   char buf[MAX_BUF];
   
   if ( (fd = open(filename, O_RDONLY)) < 0) {
      printf("Cannot open file ...");
      exit(EXIT_FAILURE);
   }

   /* Scrive il contenuto del file 'filename' in output, un carattere
    * per volta */
   while ( (n = read(fd, buf, MAX_BUF)) > 0)
      write (STDOUT_FILENO, buf, n);

   close(fd);
   return(EXIT_SUCCESS);
}


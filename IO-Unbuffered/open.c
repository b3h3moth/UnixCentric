#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> /* O_RDONLY */

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
   char buf[10];
   
   if ( (fd = open(filename, O_RDONLY)) < 0) {
      printf("Cannot open file ...");
      exit(EXIT_FAILURE);
   }

   /* Scrive il file /etc/passwd in output; 
    * il parametro 1 della write() sta per standard output */
   while ( (n = read(fd, buf, 10)) > 0) {
      write (1,buf,n);
   }

   close(fd);
   return(EXIT_SUCCESS);
}


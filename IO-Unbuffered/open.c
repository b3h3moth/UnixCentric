#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
   char *filename="/etc/passwd";
   int fd, n;
   char buf[10];
   
   if ( (fd = open(filename, O_RDONLY)) < 0) {
      printf("Cannot open file ...");
      exit(1);
   }

   /* Scrive il file /etc/passwd in output; 
    * il parametro 1 della write() sta per standard output */
   while ( (n = read(fd, buf, 10)) > 0) {
      write (1,buf,n);
   }

   printf(".");

   close(fd);
   return(EXIT_SUCCESS);
}


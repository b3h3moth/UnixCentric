#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>

/* Lo scopo del programma e' di leggere il contenuto di una directory mediante
l'utilizzo della fdopendir(), del tutto simile alla opendir(), ad eccezione del
fatto che lavora sul file descriptor, piuttosto che sullo stream come la 
opendir() stessa. */

int main(int argc, char *argv[]) {
   int dfd;
   DIR *dir;
   struct dirent *dp;

   if (argc < 2) {
      fprintf(stderr, "Uso: %s <dirname>\n", argv[0]);
      exit(EXIT_FAILURE);
   }
   
   dfd = open(argv[1], O_RDONLY);

   /* fdopendir() apre la directory specificata dal file descriptor 
   precedentemente aperto */
   if ((dir = fdopendir(dfd)) == NULL) {
      fprintf(stderr, "Err.:(%d) - %s: %s\n", errno, strerror(errno), argv[1]);
      exit(EXIT_SUCCESS);
   }

   /* Si eliminano dalla stampa le directory predefinite '.' e '..' */
   while ((dp = readdir(dir)) != NULL) {
      if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
      	 continue;
      else
      	 printf("%s\n", dp->d_name);
   }
   
   while ((closedir(dir) == -1) & (errno == EINTR))
      ;

   return(EXIT_SUCCESS);
}

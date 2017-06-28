#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

/* Lo scopo del programma e' di fornire la lista dei file in modo ordinato 
grazie all'utilizzo della funzione scandir() */

int main(int argc, char *argv[]) {
   DIR *dfd;
   struct dirent *dp;

   if (argc < 2) {
      fprintf(stderr, "Uso: %s <dirname>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   if ((dfd = opendir(argv[1])) == NULL) {
      fprintf(stderr, "Err.:(%d) - %s: %s\n", errno, strerror(errno), argv[1]);
      exit(EXIT_SUCCESS);
   }

   while ((dp = readdir(dfd)) != NULL) {
      if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
      	 continue;
      else
      	 printf("%s\n", dp->d_name);
   }
   
   closedir(dfd);

   exit(EXIT_SUCCESS);
}

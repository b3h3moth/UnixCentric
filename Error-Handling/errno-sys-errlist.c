#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv) {
   FILE *fd = fopen("file.txt","r");

   if (!fd) {
      fprintf(stderr, "-> %s\n", sys_errlist[errno]);
      exit(13);
   }

   return(EXIT_SUCCESS);
}

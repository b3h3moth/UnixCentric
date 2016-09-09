#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 512

/* La funzione 'int setvbuf(FILE *stream, char *buf, int mode, size_t size)' 
definisce la bufferizzazione dello stream. */

int main(void) {
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
      fprintf(stderr, "Open file failed: %s\n", strerror(errno));
      return 1;
    }


   if (setvbuf(stdout, buf, _IOFBF, MAX_BUF)) {
      exit(EXIT_FAILURE);
   }

   fprintf(stdout, "Thanks ");
   fprintf(stdout, "fflush()\n");
   fflush(stdout);

   fprintf(stdout, "come on baby, it's late\n");
   sleep(2);
   
   return EXIT_SUCCESS;
}

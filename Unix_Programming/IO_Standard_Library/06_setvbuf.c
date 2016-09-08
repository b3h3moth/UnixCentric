#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 512

/* La funzione 'int setvbuf(FILE *stream, char *buf, int mode, size_t size)' 
definisce la bufferizzazione dello stream. */

int main(void) {
   char buf[MAX_BUF];

   fprintf(stdout, "Buffering ...\n");

   if (setvbuf(stdout, buf, _IOFBF, MAX_BUF)) {
      fprintf(stderr, "Err. Set buffering failed: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
   }
   
   return EXIT_SUCCESS;
}

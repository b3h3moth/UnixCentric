#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define AUTHOR		"Luca Suriano"
#define MAIL_AUTHOR	"luka@linux.it"

int main(int argc, char *argv[])
{
   /*
    * La funzione tmpnam() ha il compito di generare il percorso di un nuovo
    * file temporaneo che non esiste ancora
    */
   char tmp_pathname[L_tmpnam];	/* Temp File pathname */
   FILE *tmpf = 0;		/* Opeened temp file */

   if (!(tmpnam(tmp_pathname)) ) {
      fprintf(stderr, "%s: generating a temp file name.\n", (char *)strerror(errno));
      abort();
   }

   printf("Using temp file: %s\n", tmp_pathname);

   if (!(tmpf = fopen(tmp_pathname,"w")) ) {
      fprintf(stderr, "%s: creating temp file name %s\n", (char *)strerror(errno), tmp_pathname);
      abort();
   }

   return(EXIT_SUCCESS);
}

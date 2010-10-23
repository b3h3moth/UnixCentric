#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 512

int main(int argc, char *argv[])
{
   /* La funzione tmpnam() ha il compito di generare il percorso di un nuovo
    * file temporaneo, il quale naturalmente ancora non esiste, in pratica
	* genera una stringa; per temporaneo si intende che tale file sara' creato 
	* nella directory /tmp */

   char *tmp_pathname;		/* Percorso del file temporaneo */
   FILE *ftmp = 0;			/* File temporaneo */
   char buf[MAX_BUF];		/* Servira' se tutto andra' bene, per contenere
   							   che sara' scritto nel file temporaneo */

   if (!(tmp_pathname = tmpnam(NULL)) ) {
      fprintf(stderr, "%s: generazione file temporaneo.\n", (char *)strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* tmp_pathname contiene un puntatore al percorso del file temporaneo */
   printf("File temporaneo: %s\n", tmp_pathname);

   /* Se tutto e' andato a buon fine, mediante la fopen() si apre un file nella
	* directory /tmp */
   if ((ftmp = fopen(tmp_pathname,"w")) == NULL ) { 
      fprintf(stderr, "%s: creazione file temporaneo %s\n", (char *)strerror(errno), tmp_pathname);
      exit(EXIT_FAILURE);
   }

   /* Scrivo sui file temporaneo */
   fputs("Sto scrivendo sul file temporaneo appena creato.\n"
   		 "Da notare che la tmpnam() restituisce un puntatore\n", ftmp);

   /* Riporto il puntatore all'inizio del file */
   rewind(ftmp);

   /* Leggo dal file temporaneo */
   if ( (fgets(buf, 512, ftmp)) == NULL) {
      fprintf(stderr, "%s: lettura da file temporaneo %s\n", (char *)strerror(errno), ftmp);
	  exit(EXIT_FAILURE);
   }

   fputs(buf, stdout);


   fclose(ftmp);

   return(EXIT_SUCCESS);
}

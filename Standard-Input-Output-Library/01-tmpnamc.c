#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 1024

/* 
 * Utilizzo di tmpnam() con argomento NULL - Prototipo: char *tmpnam(char *s); 
 */

int main(int argc, char *argv[])
{
   /* La funzione tmpnam() ha il compito di generare il percorso di un nuovo
    * file temporaneo, il quale naturalmente ancora non esiste, in pratica
	* genera una stringa; tale file sara' creato nella directory /tmp */

   char *tmp_pathname;		/* Percorso del file temporaneo */
   FILE *ftmp = 0;			/* File temporaneo */
   char buf[MAX_BUF];		/* Servira' se tutto andra' bene, per contenere
   							   cio' che sara' scritto nel file temporaneo */

   /* tmpnam() puo' accettare come argomento un puntatore a char oppure, come
	* in questo caso, NULL, e il percorso sara' valido fino alla successiva 
	* chiamata di tmpnam() proprio perche' non e' stato fornito un argomento */
   if (!(tmp_pathname = tmpnam(NULL)) ) {
      fprintf(stderr, "%s: generazione file temporaneo.\n", (char *)strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* tmp_pathname contiene il puntatore a un buffer, ovvero il percorso del
	* file temporaneo */
   printf("File temporaneo: %s\n", tmp_pathname);

   /* Si chiama la fopen() per la creazione del file */
   if ((ftmp = fopen(tmp_pathname, "w")) == NULL ) { 
      fprintf(stderr, "%s: creazione file temporaneo %s\n", (char *)strerror(errno), tmp_pathname);
      exit(EXIT_FAILURE);
   }

   /* Si scrive sui file temporaneo */
   fputs("Sto scrivendo sul file temporaneo appena creato.\n"
   		 "Da notare che la tmpnam() restituisce un puntatore\n", ftmp);

   /* Si riporta il puntatore all'inizio del file */
   rewind(ftmp);

   /* Leggo dal file temporaneo */
   if ( (fgets(buf, sizeof(buf), ftmp)) != NULL) {
      fprintf(stderr, "%s: lettura da file temporaneo %s\n", (char *)strerror(errno), ftmp);
	  exit(EXIT_FAILURE);
   }

   /* Si stampa il contenuto del file */
   fputs(buf, stdout);

   /* Il puntatore al file viene deallocato */
   fclose(ftmp);

   return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 516

/* 

Prototipo:
	char *tmpnam(char *s);

Note:
	Utilizzo di tmpnam() con argomento NULL
	POSIX tuttavia consiglia di utilizzare mkstemp() invece di tmpnam()

*/

int main(int argc, char *argv[])
{
   /* La funzione tmpnam() ha il compito di generare il percorso di un nuovo
    * file temporaneo, il quale naturalmente ancora non esiste, in pratica
	* genera una stringa; tale file sara' creato nella directory /tmp */

   char *tmp_pathname;		/* Percorso del file temporaneo */
   FILE *ftmp;				/* File temporaneo */
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
   if ((ftmp = fopen(tmp_pathname, "w+")) == NULL ) { 
      fprintf(stderr, "%s: creazione file temporaneo %s\n", (char *)strerror(errno), tmp_pathname);
      exit(EXIT_FAILURE);
   }

   /* Il puntatore al file viene deallocato */
   fclose(ftmp);

   return(EXIT_SUCCESS);
}

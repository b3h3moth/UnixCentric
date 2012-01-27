#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/*
 Talune funzioni della libreria standard adottano un intero positivo per
 indicare un eventuale errore nel comportamento della funzione, il relativo
 codice di errore va a collocarsi nella variabile 'errno'.

 Da notare che in linea di massima sia le funzioni della libreria standard sia
 le system call adottano dei valori generici atti ad indicare lo stato di
 errore, ossia '-1', 'NULL' ed 'EOF', ma in questi casi si comprende solo 
 l'occorrenza di un errore, ignorandone tuttavia la natura; il compito della
 variabile 'errno', associata a specifiche macro definite in errno.h, e' proprio
 quello di fornire il tipo di errore occorso.

 Come accennato pocanzi, diverse macro che indicano la specificita' di ciascun
 codice di errore sono definite in <errno.h>, esse iniziano con il carattere E
 e naturalmente sono a tutti gli effetti nomi riservati.
*/


int main(int argc, char **argv) {
   int fd;

   /*
    All'inizio di una 'chiamata' errno e' impostato a 0, per cui qualsiasi
    altro valore indichera' ad errno un codice di errore
   */
   if ( (fd = open("/dubito/che/esista/questo/file", O_RDONLY)) < 0) {
      if (errno != 0) { 
      	 fprintf(stderr, "Err.:(%d) Il file non esiste\n", errno);
	 /*
	  Una sottigliezza, uscire dal programma fornendo alla funzione exit()
	  il parametro 'errno'; il codice di uscita del programma peraltro si
	  puo' verificare eseguendo via terminale "echo $?" 
	 */
	 exit(errno);
      }
      /*
       Non tutte le funzioni o le system call salvano un codice di errore nella
       variiabile 'errno'.
      */
      exit(EXIT_FAILURE); 
   }

   close(fd);

   return(EXIT_SUCCESS);
}

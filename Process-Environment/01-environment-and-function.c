#include <stdio.h>
#include <stdlib.h>

/* Il programma si basa interamente su questa funzione, che legge un file in
 * input e lo stampa a video.
 *
 * Uso: e' sufficiente fornire un file in input*/
void LeggiDaFile(char *fin)
{
    FILE *ptr_file;
    int byte;

    if ( (ptr_file = fopen(fin,"r")) == NULL ) {
       fprintf(stderr,"errore\n");
    } else {
       while((byte = fgetc(ptr_file)) != EOF)
	  printf("%c", byte);
    }

}

/* Il programma e' stato scritto per far vedere come e' possibile lavorare in
 * modo molto efficace con argc e argv */
int main(int argc, char *argv[]) {

   if (argc < 2) {
      printf("ATTENZIONE: \"%s\" ha bisogno di un argomento", argv[0]);
      exit(1);
   }
   else {
      LeggiDaFile(argv[1]);
   }

   return(EXIT_SUCCESS);
}


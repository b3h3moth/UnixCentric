#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 80

/*
 * Il seguente programma conta le righe di un file ricevuto come parametro in
 * input.
 * Uso: ./a.out /etc/passswd
 */

int main(int argc, char *argv[]) {
   FILE *f_input;
   char riga[MAX_LEN];
   int conta_righe, x;

   if (argc < 2) {
      fprintf(stderr, "ATTENZIONE: Inserire un argomento\n");
      exit(1);
   }

   if ( (f_input = fopen(argv[1], "r") ) == NULL) {
      fprintf(stderr,"Errore nell'apertura del file \"%s\".\n", argv[1]);
      exit(1);
   }

   conta_righe = 0;
   while (fgets(riga, MAX_LEN, f_input) != NULL) {
      conta_righe++;
   }
   
   printf("Il file \"%s\" contiene \"%d\" righe.\n", argv[1], conta_righe);

   for(x=0; x<argc; x++) {
      printf("Argomento argv[%d] = %s\n", x, argv[x]);
   }

   fclose(f_input);

   return(EXIT_SUCCESS);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
HEADER    : <stdlib.h>
PROTOTYPE : int atoi(const char *str);
SEMANTICS : La funzione atoi() converte la porzione iniziale della stringa 
            puntata da 'str' in un intero.
RETURNS   : La stringa convertita in intero
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
   char buf[] = "31/03/1973";
   int value;

   if (argc != 2) {
       fprintf(stderr, "Uso: %s <intero>|<intero>+<stringa>\n", argv[0]);
       exit(EXIT_FAILURE);
   }

   printf("     Stringa iniziale: %s\n", buf);

   value = atoi(buf);
   printf("Stringa convertita in: %d\n", value);

   /* Molto utile allorquando si deve lavorare coi parametri */
   int choice;

   choice = atoi(argv[1]);

   printf("   Parametro iniziale: %s\n", argv[1]);
   printf(" Parametro convertito: %d\n", choice);

   return(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* L'allocazione dinamica della memoria è usata di continuo con le stringhe, in
tal caso peraltro il lavoro sara' facilitato, poichè si dovrà utilizzare un
char che corrisponde esattamente a 1 byte, per cui, una stringa di N caratteri 
sara' sizeof(char) * N; da non dimenticare di aggiungere un byte per il 
carattere di fine stringa \0. */

char *concat(const char *str1, const char *str2);
void freeMemory(char *block);

int main(void) {
   char *full_string = concat("Learning"," c-ansi (c11)");

   printf("%s\n", full_string);
   
   freeMemory(full_string);

   return(EXIT_SUCCESS);
}

/* La funzione concat() concatena due stringhe */
char *concat(const char *str1, const char *str2)
{
   char *result;

   result = malloc(strlen(str1) + strlen(str2) +1);

   if (result == NULL) {
      fprintf(stderr, "Err.:%d - malloc() %s\n", errno, strerror(errno));
      exit(EXIT_FAILURE);
   }

   strcpy(result, str1);
   strcat(result, str2);

   return result;
}

/* Libera la memoria occupata dalle stringhe concatenate */
void freeMemory(char *block)
{
   printf("-- set the memory free\n");
   free(block);
   block = NULL;
}
